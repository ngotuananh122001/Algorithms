#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int n; // nodes
int m; // edges
vector<int> e[MAXN];
int color[MAXN];
bool isBipariteGraph = true;

void dfs(int u) {
    for (auto v : e[u]) {
        if (color[v] == color[u]) {
            isBipariteGraph = false;
            return;
        }

        if (color[v] == 0) {
            if (color[u] == 1) {
                color[v] = 2;
            } else {
                color[v] = 1;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    int u, v;
    while (m--) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; i++) {
        if (isBipariteGraph == false) {
            break;
        }

        if (color[i] == 0) {
            color[i] = 1;
            dfs(i);
        }
    }

    cout << isBipariteGraph << endl;
}
