#include <bits/stdc++.h>
using namespace std;

const long long INF = 2e12;
const int N = 1e3;

struct Edge {
    int v; // đỉnh hàng xóm của u
    long long w; // trọng số trên cạnh u->v
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

int n; // số đỉnh
int m; // số cạnh
int s; // đỉnh nguồn

// edges[u] chứa tập hơp các cạnh (u,v)
// và trọng số trên cạnh đó
vector<Edge> edges[N];

// d[u] là độ dài đường đi ngắn nhất từ s->u
long long d[N];

// trace[v] = u -> u là đỉnh đi trước trong đường
// đi ngắn nhất từ s->v. Eg: s->...-> u -> v;
int trace[N];

void input() {
    scanf("%d%d%d", &n, &m, &s);

    for (int i = 1; i <= m; i++) {
        int u, v;
        long long w;
        scanf("%d%d%lld", &u, &v, &w);
        edges[u].push_back({v, w});
    }
}

void dijkstra() {
    fill_n(d, n, INF);
    fill_n(trace, n, -1);

    d[s] = 0;
    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({s, d[s]});

    while (!pq.empty()) {
        // Lấy ra đỉnh có d nhỏ nhất
        // Đỉnh chóp của min-heap
        Node x = pq.top(); //o(1)
        pq.pop(); // o(logn)

        int u = x.u;

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

int main() {
    freopen("dijkstra.txt", "r", stdin);
    input();

    dijkstra();

    for (int i = 0; i < n; i++) {
        if (d[i] == INF) {
            cout << -1 << endl;
        } else {
            cout << d[i] << endl;
        }
    }
    return 0;
}

