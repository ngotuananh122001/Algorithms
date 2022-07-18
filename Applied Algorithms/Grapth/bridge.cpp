#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10;

vector<int> g[maxN];
int n, m;
int bridge = 0;
bool joint[maxN];
int timeDfs = 0;
int low[maxN], num[maxN];

void input() {
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dfs(int u, int pre) {
    int child = 0;
    num[u] = low[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == pre)
            continue;

        if (num[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v])
                bridge++;

            child++;

            if (u == pre) {
                if (child > 1) joint[u] = true;
            } else if (low[v] >= num[u])
                joint[u] =true;

            continue;
        }

        // v da duoc tham
        low[u] = min(low[u], num[v]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    input();

    // Khoi tao ban dau
    for (int u = 1; u <= n; u++) {
        num[u] = -1;
        joint[u] = false;
    }

    for (int u = 1; u <= n; u++) {
        if (num[u] == -1) {
            dfs(u, u);
        }
    }

    int numOfJoint = 0;
    for (int i = 1; i <= n; i++) {
        if (joint[i])
            numOfJoint++;
    }

    cout << numOfJoint << " " << bridge << endl;
    return 0;
}

