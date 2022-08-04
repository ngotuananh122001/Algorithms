#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v;
	long long w;
};

const int N = 1e3;
const long long INF = 2000000000000000000LL;

vector<Edge> edges; // mang canh
int n; // so dinh
int m; // so canh
int s; // dinh nguon
long long d[N]; // d[u] cho biet duong di ngan nhat tu S->u
int trace[N]; // trace[v] = u, cho biet v la dinh di truoc trong duong di ngan
// nhat tu s->v
vector<int> negCycle;

void BellmanFord() {
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

vector<int> TracePath(int u) {
	if (u != s && trace[u] == -1) {
		return vector<int> (0);
	}

	vector<int> path;
	while (u != -1) {
		path.push_back(u);
		cout << u << " ";
		u = trace[u];
	}

	cout << "Done" << endl;
	reverse(path.begin(), path.end());

	return path;
}

void input() {
	scanf("%d%d%d", &n, &m, &s);

	for (int i = 0; i < m; i++) {
		Edge e;
		scanf("%d%d%lld", &e.u, &e.v, &e.w);
		edges.push_back(e);
	}
}

int main() {
	freopen("inp.txt", "r", stdin);
	input();

	BellmanFord();
    if (FindNegativeCycle()) {
        cout << "Negative cycle: ";
        for (auto u : negCycle) cout << u << " ";
    } else {
        cout << "Khong ton tai chu trinh am";
    }
	return 0;
}

