// https://codeforces.com/problemset/problem/20/C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const long long INF = 2e18;
int n; // vertices
int m; // edges

struct Edge {
    int v;
    long long w;
};

struct Node {
    int u;
    long long dist_u;
};

struct cmp {
    bool operator() (Node a, Node b) {
        return a.dist_u > b.dist_u;
    }
};

// Biểu diễn đồ thị
vector<Edge> edges[N];
long long d[N];
int trace[N];

void dijkstra(int s) {
    fill_n(d, n + 1, INF);
    fill_n(trace, n + 1, -1);

    priority_queue<Node, vector<Node>, cmp> pq;
    d[s] = 0;
    pq.push({s, d[s]});

    while (!pq.empty()) {
        /* Lấy ra node chưa được tối ưu có đường đi nhỏ
        nhất (từ s tới )
            Sau khi được lấy ra, node này sẽ không bao giờ
            được đưa lại vào trong queue nữa bởi vì nó đã được
            tối ưu rồi và không thể có đường đi nào khác
            s->... -> v->u tốt hơn
        */
        int u = pq.top().u;
        pq.pop();

        for (auto e : edges[u]) {
            int v = e.v;
            long long w = e.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                trace[v] = u;
                pq.push({v, d[v]});
            }
        }
    }
}

void trace_path(int s, int u) {
    dijkstra(s);
    if (d[u] == INF) {
        cout << -1 << endl; // no path
        return;
    }

    vector<int> path;
    while (u != -1) {
        path.push_back(u);
        u = trace[u];
    }

    reverse(path.begin(), path.end());
    for (auto x : path) {
        cout << x << " ";
    }
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        long long w;
        scanf("%d%d%lld", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
}

int main()
{
    freopen("shortest_path.txt", "r", stdin);
    input();

    trace_path(1, n);
	return 0;
}
