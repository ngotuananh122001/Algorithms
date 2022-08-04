// Longest path on a tree
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 7;

struct Edge {
    int v;
    long long w;
};

int n; // số đỉnh của cây
vector<Edge> g[MAX];
int d[MAX]; // d[v] is the distance from u
int p[MAX]; // p[v] is the parent of v

void Input() {
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        long long w;
        scanf("%d %d %lld", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}

void bfs(int s) {
    for (int i = 1; i <= n; i++) {
        d[i] = -1;
        p[i] = -1;
    }

    p[s] = s;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto e : g[u]) {
            int v = e.v;
            long long w = e.w;
            // v là đỉnh cha của u, nên nó đã được duyệt rồi
            if (p[u] == v) continue;
            d[v] = d[u] + w;
            p[v] = u;
            q.push(v);
        }
    }
}

int FindMax() {
    int x = 1;
    for (int u = 2; u <= n; u++) {
        if (d[u] > d[x]) {
            x = u;
        }
    }

    return x;
}

int main()
{
    Input();
    bfs(1);
    int x = FindMax();
    bfs(x);
    int y = FindMax();
    cout << d[y];
	return 0;
}
