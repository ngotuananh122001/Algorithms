#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+1;
int n;
int a[MAXN];

int maxSubsequence(int n, int a[]) {
    int S[n];
    S[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (S[i+1] < 0) {
            S[i] = a[i];
        } else {
            S[i] = S[i+1] + a[i];
        }
    }

    int ans = S[0];
    for (int i = 1; i < n; i++)
        ans = max(ans, S[i]);

    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    printf("%d", maxSubsequence(n, a));
}
