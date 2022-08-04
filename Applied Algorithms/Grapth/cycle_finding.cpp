#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

const int N = 1e4;
const long long INF = 2000000000000000000LL;

vector<Edge> edges; // mang canh
int n; // so dinh
int m; // so canh
long long d[N]; // d[u] cho biet duong di ngan nhat tu s->u
int trace[N]; // trace[v] = u, cho biet v la dinh di truoc trong duong di ngan
// nhat tu s->v
vector<int> negCycle;

void BellmanFord(int s) {
    fill_n(d, n, INF);
    fill_n(trace, n, -1);

    d[s] = 0;
    for (int i = 1; i < n; i++) {
        for (auto e : edges) {
            int u = e.u;
            int v = e.v;
            long long w = e.w;
            if (d[u] != INF && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                trace[v] = u;
            }
        }
    }
}

bool FindNegativeCycle() {
    // Run Bellman-Ford truoc do, de xac dinh mang d[] va trace[]
    int negStart = -1; // đỉnh bắt đầu, lính canh
    for (auto e : edges) {
        int u = e.u;
        int v = e.v;
        long long w = e.w;
        if (d[u] != INF && d[v] > d[u] + w) {
            d[v] = -INF;
            trace[v] = u;
            negStart = v;
        }
    }

    if (negStart == -1) return false;

    int u = negStart;
    for (int i = 1; i <= n; i++) {
        u = trace[u]; // đưa u về chu trình âm
    }

    negCycle = vector<int> (1, u);
    for (int v = trace[u]; v != u; v = trace[v]) {
        negCycle.push_back(v);
    }

    reverse(negCycle.begin(), negCycle.end());
    return true;
}

void input() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        Edge e;
        scanf("%d%d%lld", &e.u, &e.v, &e.w);
        edges.push_back(e);
    }
}

int main() {
    // freopen("inp.txt", "r", stdin);
    input();

    for (int s = 1; s <= n; ++s) {
        BellmanFord(s);
        if (FindNegativeCycle()) {
            cout << "YES" << endl;
            for (auto u : negCycle) cout << u << " ";
            cout << negCycle[0] << endl;
            return 0;
        }
    }

    cout << "NO";

    return 0;
}
