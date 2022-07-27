#include <bits/stdc++.h>
using namespace std;

const long long INF = 2e12;
const int N = 1e3;

struct Edge {
    int v; // đỉnh hàng xóm của u
    long long w; // trọng số trên cạnh u->v
};

int n; // số đỉnh
int m; // số cạnh
int s; // đỉnh nguồn

// edges[u] chứa tập hơp các cạnh (u,v)
// và trọng số trên cạnh đó
vector<Edge> edges[N];

// d[u] là độ dài đường đi ngắn nhất từ s->u
long long d[N];

// p[u] cho biết đỉnh u đã được tối ưu chưa
bool p[N];

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
    fill_n(p, n, false);
    fill_n(trace, n, -1);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int uBest = -1;
        long long Min = INF;
        for (int u = 0; u < n; ++u) {
            if (d[u] < Min && p[u] == false) {
                uBest = u;
                Min = d[u];
            }
        }

        int u = uBest;
        p[u] = true;
        for (auto e : edges[u]) {
            int v = e.v;
            long long w = e.w;

            // Không cần kẹp đk p[v] == false
            // vì một khi d[v] > d[u] + w thì
            // chắc chắn đường đi từ s->v chưa được tổi ưu
            // đồng nghĩa với p[v] phải = false
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                trace[v] = u;
            }
        }
    }
}

int main()
{
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

