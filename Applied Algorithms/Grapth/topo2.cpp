#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n, m; // so dinh, so cung
vector<int> g[N]; // danh sach ke
bool visited[N];
int inDeg[N]; // bac vao
vector<int> topo;

void bfs() {
	queue<int> qu;
	
	for (int i = 1; i <= n; i++) {
		if (inDeg[i] == 0) {
			qu.push(i);
		}
	}
	
	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		
		topo.push_back(u);
		
		for (auto v : g[u]) {
			inDeg[v]--;
			if (inDeg[v] == 0) {
				qu.push(v);
			}
		}
	}
}

void input() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        inDeg[v]++;
    }

}
int main() {
	memset(visited, 0, sizeof(visited));
	input();
	
	bfs();
	
	int ans[N];
	int cnt = 0;
	
	for (auto v : topo) {
		ans[v] = ++cnt;
	}
	
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
}

