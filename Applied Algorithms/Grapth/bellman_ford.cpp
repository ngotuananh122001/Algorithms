#include <bits/stdc++.h>
using namespace std;

const long long INF = 2000000000000000000LL;
struct Edge {
    int u, v;
    long long w; // cạnh từ u đến v, trọng số w
};

int n;
int m;
int S;
vector<Edge> e;
vector<long long> D;
vector<int> trace;
vector<int> negCycle;

void bellmanFord(int n, int S, vector<Edge> &e, vector<long long> &D, vector<int> &trace) {
    // e: danh sách cạnh
    // n: số đỉnh
    // S: đỉnh bắt đầu
    // D: độ dài đường đi ngắn nhất
    // trace: mảng truy vết đường đi
    // INF nếu không có đường đi
    // -INF nếu có đường đi âm vô tận
    D.resize(n, INF);
    trace.resize(n, -1);

    D[S] = 0;
    for(int T = 1; T < n; T++) {
        for (auto E : e) {
            int u = E.u;
            int v = E.v;
            long long w = E.w;
            if (D[u] != INF && D[v] > D[u] + w) {
                D[v] = D[u] + w;
                trace[v] = u;
            }
        }
    }
}

bool findNegativeCycle(int n, vector<long long> &D, vector<int> &trace, vector<int> &negCycle) {
    // mảng D và trace đã được chạy qua thuật toán Bellman-Ford
    int negStart = -1; // đỉnh bắt đầu
    for (auto E : e) {
        int u = E.u;
        int v = E.v;
        long long w = E.w;
        if (D[u] != INF && D[v] > D[u] + w) {
            // cout << "Toi uu canh (" << u << ", " << v << ")";
            D[v] = -INF;
            trace[v] = u;
            negStart = v; // đã tìm thấy -INF
        }
    }

    if (negStart == -1) return false; // không có chu trình âm

    int u = negStart;
    for (int i = 0; i < n; i++) {
        u = trace[u]; // đưa u về chu trình âm
    }

//    for (int i = 0; i < n; i++) {
//        printf("trace[%d] = %d\n", i, trace[i]);
//    }

    negCycle = vector<int> (1, u);
    for (int v = trace[u]; v != u; v = trace[v]) {
        //cout << v << " ";
        negCycle.push_back(v);
    }
    reverse(negCycle.begin(), negCycle.end());

    return true;
}

void input() {
	scanf("%d%d%d", &n, &m, &S);

	for (int i = 0; i < m; i++) {
		Edge x;
		scanf("%d%d%lld", &x.u, &x.v, &x.w);
		e.push_back(x);
	}
}

int main() {
	freopen("inp.txt", "r", stdin);
	input();

	bellmanFord(n, S, e, D, trace);

    if (findNegativeCycle(n, D, trace, negCycle)) {
        cout << "Negative cycle: ";
        for (auto u : negCycle) cout << u << " ";
    } else {
        cout << "Khong ton tai chu trinh am";
    }


	return 0;
}

