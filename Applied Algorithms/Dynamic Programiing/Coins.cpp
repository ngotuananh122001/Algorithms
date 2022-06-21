#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;
int D[MAXN];
int n; // Num of coin type
int x; // Price
int S[MAXN]; // S[i] = min coins which total is equal to x
int pi[MAXN];

int MinCoin() {
    for (int i = 0; i <= x; i++) {
        S[i] = INT_MAX;
        pi[i] = INT_MAX;
    }

    S[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (D[j] > i) {
                continue;
            }

            if (S[i - D[j]] == INT_MAX) {
                continue;
            }

            if (S[i] > 1 + S[i - D[j]]) {
                S[i] = 1 + S[i - D[j]];
                pi[i] = i - D[j];
            }
        }
    }

    return S[x];
}

void Trace() {
    int i = x;
    while (pi[i] != INT_MAX) {
        cout << i - pi[i] << " ";
        i = pi[i];
    }

    cout << endl;
}
int main() {
    scanf("%d%d", &n, &x);

    for (int i = 0; i < n; i++) {
        scanf("%d", D + i);
    }

    cout << MinCoin() << endl;
    Trace();
}
