// https://codeforces.com/group/Ir5CI6f3FD/contest/276073/problem/A

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;
int n;
int l1, l2;
int a[MAXN];
int S[MAXN]; // S[i] là lời giải bài toán con với dãy A1, A2..., Ai va kết thúc tại Ai

void input() {
    scanf("%d%d%d", &n, &l1, &l2);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
}

void solve() {
    S[0] = a[0];
    for (int i = 1; i < n; i++) {
        S[i] = a[i];

        // l1 <= i - j <= l2 && j >= 0
        for (int j = i - l1; j >= i - l2 && j >= 0; j--) {
            S[i] = max(S[i], S[j] + a[i]);
        }
    }

    int ans = S[0];
    for (int i = 1; i < n; i++) {
        ans = max(ans, S[i]);
    }

    cout << ans << endl;
}

int main() {
    input();
    solve();
}
