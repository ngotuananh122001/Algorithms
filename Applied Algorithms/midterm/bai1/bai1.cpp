#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
int a[MAXN];
int n;


int main() {
   // freopen("3-input.txt", "r", stdin);
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }

    int ans = 0;
    int i = 1;
    for (int i = 2; i <= n - 1; i++) {
        if (a[i] > a[i-1] && a[i] > a[i+1]) {
            ans++;
        }
    }

    cout << ans;
}

