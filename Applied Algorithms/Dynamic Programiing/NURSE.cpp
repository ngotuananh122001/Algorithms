#include <bits/stdc++.h>
using namespace std;

int n; // so ngay
int k1;
int k2;
int S0[1000];
int S1[1000];

int solve() {
    memset(S0, 0, sizeof(S0));
    memset(S1, 0, sizeof(S1));
    S0[1] = 1;
    S1[k1] = 1;
    S0[0] = 1;
    for (int i = k1 + 1; i <= n; i++) {
        S0[i] = S1[i - 1];
        S1[i] = 0;
        for (int j = k1; j <= k2; j++) {
            if (i - j >= 0)
                S1[i] += S0[i - j];
        }
    }

    return S0[n] + S1[n];
}

int main() {
    cin >> n >> k1 >> k2;
    cout << solve();
}
