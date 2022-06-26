#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;
const int Q = 1e9 + 7;
int a[N];
int n;
int SC[N];
int SL[N];
bool BL[N];
bool BC[N];

void solve() {
    SC[0] = 0;
    SL[0] = 0;
    if (a[1] % 2 == 0) {
        SC[1] = 1; BC[1] = true;
        SL[1] = 0; BL[1] = false;
    } else {
        SC[1] = 0; BC[1] = false;
        SL[1] = 1; BL[1] = true;
    }

    for (int i = 2; i <= n; i++) {
        // neu a[i] chan
        if (a[i] % 2 == 0) {
            if (BC[i-1]) {
                SC[i] = SC[i-1] + 1;
            } else {
                SC[i] = 1;
            }

            BC[i] = true;

            if (BL[i-1]) {
                SL[i] = SL[i-1];
                BL[i] = true;
            } else {
                BL[i] = false;
            }

            continue;
        }

        // neu a[i] le
        if (BL[i-1]) {
            SC[i] = SL[i - 1];
            BC[i] = true;
        } else {
            BC[i] = false;
        }

        if (BC[i-1]) {
            SL[i] = SC[i-1] + 1;
        } else {
            SL[i] = 1;
        }

        BL[i] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += SC[i];
    }

    cout << ans;
}

int main() {
    // freopen("test.txt","r",stdin);
    memset(BC, 0, sizeof(BC));
    memset(BL, 0, sizeof(BL));

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }

    solve();

}
