#include <bits/stdc++.h>
#define N 10000001;
int a[N];
int n;
int S[N];
bool b[N];

int DP(int i) {
    if (i == 1) {
        // basecase, smallest sub-problem
        S[1] = a[1];
    } else {
        if (b[i])
            return S[i]
        int t1 = DP(i-1); // call DP recursively for solving sub-problem
        S[i] = max(t1+a[i], a[i]);
    }

    return S[i];
}

void input() {

cin >>n ;
for (int i = 1; i <= n; i++) cin >> a[i];
}
int main() {
    input();
    ans = DP(1);
    for (int i = 2; i <=n i++)
        ans = max(ans, DP(i));
}
