#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;
int n; // nodes
int m; // edges
vector<int> G[MAXN]; // G[u] is adjacent nodes of u
bool visted[MAXN];

void dfs(int u) {
    visted[u] = true;
    for (int v : G[u]) {
        if (!visted[v])
            dfs(v);
    }
}

int main() {
    freopen("connected_component.txt", "r", stdin);
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    memset(visted, 0, sizeof(visted));
    int numOfCC = 0;
    for (int i = 1; i <= n; i++) {
        if (!visted[i]) {
            dfs(i);
            numOfCC++;
        }
    }

    cout << numOfCC << endl;
}
