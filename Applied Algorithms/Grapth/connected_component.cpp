#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

int n; // nodes
int m; // edges
int ans;

vector<int> e[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (auto v : e[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> m;
    while (m-- > 0) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ans++;
            dfs(i);
        }
    }

    cout << ans << endl;
    return 0;
}
