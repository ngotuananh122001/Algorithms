#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int n; // so node của đồ thị G
int k; // so chặng của k-path
int m; // số cạnh của đồ thị G
vector<int> G[50];
bool visited[50];
int ans = 0;

// u là đỉnh được chọn trên k-path
// cnt là số chặng hiện tại
void dfs(int u, int cnt) {
    for (auto v : G[u]) {
        if (!visited[v]) {
            visited[v] = true; // đỉnh v được chọn tiếp theo trên k-path
            cnt++; // một chặng mới tạo ra (u -> v)
            if (cnt == k) {
                ans++;
            }
            else
                dfs(v, cnt);
            visited[v] = false;
            cnt--;
        }
    }
}

void input() {
    cin >> n >> k;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}
int main() {
    input();
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
    }

    cout << ans / 2;
}
