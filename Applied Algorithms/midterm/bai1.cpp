#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;
int n;
int a[N];
int ans;
void input() {
    cin >> n;
    a[0] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void solve() {
    ans = INT_MIN;
    int i = 1;
    int j = 1;
    while (i <= n) {
        if (i == n) break;
        if (a[i] < a[i + 1]) {
            j++;
            i++;
        } else {
            ans = max(ans, j);
            j = 1;
            i++;
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("test.txt", "r", stdin);
    input();
    solve();
}
