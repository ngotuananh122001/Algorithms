#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;
int S[30];
int a[30][30];
int n;
bool visited[30];
int totalCost = 0;
int minCost = INT_MAX;
int ans = INT_MAX;
void input() {
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            a[i][j] = -1;
    }

    while (m--) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        a[u][v] = c;
        minCost = min(a[u][v], minCost);
    }
}

bool check(int u, int k) {
    if (visited[u]) return false;
    if (a[S[k-1]][u] == -1) return false;
    if (totalCost + a[S[k-1]][u] + (n-k+1) * minCost > ans) return false;
    return true;
}

void Try(int k) {
    for (int u = 2; u <= n; u++) {
        if (check(u, k)) {
            S[k] = u;
            visited[u] = true;
            totalCost += a[S[k-1]][u];
            if (k == n) {
                if (a[u][1] != -1) {
                    ans = min(ans, totalCost + a[u][1]);
                }

            } else {
                Try(k + 1);
            }

            visited[u] = false;
            totalCost -= a[S[k-1]][u];
        }
    }
}
int main() {
    input();
    memset(visited, 0, sizeof(visited));

    S[1] = 1;
    Try(2);
    cout << ans;
}
