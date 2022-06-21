#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 1;
int S[MAXN][MAXN];
int X[MAXN], n;
int Y[MAXN], m;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", X + i);

    for (int i = 1; i <= m ; i++)
        scanf("%d", Y + i);
}

void solve() {
    for (int j = 0; j <= m; j++) S[0][j] = 0;
    for (int i = 0; i <= n; i++) S[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i] == Y[j]) {
                S[i][j] = 1 + S[i-1][j-1];
            } else {
                S[i][j] = max(S[i][j-1], S[i-1][j]);
            }
        }
    }

    cout << S[n][m] << endl;
}
int main() {
    input();
    solve();
}
