#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+1;
int n;
int a[MAXN];

/*
    S[i] là độ dài của dãy con tăng dài nhất, mà
    bắt đầu tại a[i]
    -> Bài toán cơ sở: S[n-1] = 1;
    Công thực đệ quy:
        S[i] = max(1, S[j]) với mọi j
*/
int longestSubsequence(int n, int a[]) {
    int S[n];
    for (int i = n - 1; i >= 0; i--) {
        S[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                S[i] = max(S[i], S[j] + 1);
            }
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

    printf("%d", longestSubsequence(n, a));
}
