#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n, m; // so dinh, so cung
vector<int> g[N]; // danh sach ke
bool visited[N];
vector<int> iTopo; // danh sach topo dao nguoc
int dp[N]; // dp[i] la duong di dai nhat xuat phat tu i

void dfs(int u) {
	if (visited[u]) return;
		
	visited[u] = true;
	for (auto v : g[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
	
	iTopo.push_back(u);
}

void TopoSort() {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) dfs(i);
	}
}
void input() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }

}

void solve() {
	
	TopoSort();
	
	for (auto u : iTopo) {
		dp[u] = 0;
		for (auto v : g[u]) {
			dp[u] = max(dp[u], dp[v] + 1);
		}
	}
	
	int ans = dp[1];
	for (int i = 2; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	
	cout << ans << endl;
}
int main() {
	memset(visited, 0, sizeof(visited));
	
	input();
	
	solve();
	
}

// https://lqdoj.edu.vn/problem/longestpath

