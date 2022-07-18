#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 10;
int n;
int m;
vector<int> g[maxN];
int num[maxN], low[maxN];
int timeDfs = 0;
int bridge = 0;

void input() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void dfs(int u, int pre) {
	num[u] = low[u] = ++timeDfs;
	for (int v : g[u]) {
		if (v == pre)
			continue;
		if (num[v] == -1) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] == num[v])
				bridge++;
		} else {
			low[u] = min(low[u], num[v]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();
	for (int u = 1; u <= n; u++) {
		num[u] = -1;
	}
	
	for (int u = 1; u <= n; u++) {
		if (num[u] == -1)
			dfs(u, u);
	}
	
	cout << bridge;
}
