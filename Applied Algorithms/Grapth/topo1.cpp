#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n, m; // so dinh, so cung
vector<int> g[N]; // danh sach ke
bool visited[N];
stack<int> topo;

void dfs(int u) {
	if (visited[u]) return;
	
	visited[u] = true;
	for (auto v : g[u]) {
		if (!visited[v])
			dfs(v);
	}
	
	topo.push(u);
}

void input() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        
    }

}
int main() {
	memset(visited, 0, sizeof(visited));
	input();

	for (int u = 1; u <= n; u++) {
		if (!visited[u]) dfs(u);
	}
	
	int ans[N];
	int cnt = 0;
	while (!topo.empty()) {
		int v = topo.top();
		topo.pop();
		ans[v] = ++cnt;
	}
	
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
}

