#include <bits/stdc++.h>
using namespace std;

int n;
int b;
int a[10000];
int S[10000];
int total;
int index;
int ans;
void input() {
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
}

void Try(int k) {

    for (int v = 0;  v <= 1; v++) {
        S[k] = v;
        if (v == 0) {
            total -= a[index];
        } else {
            total += a[index];
        }

        index++;

        if (k == n - 1) {
            if (total == b) ans++;
        } else {
            Try(k + 1);
        }

        index--;

        if (v == 0) {
            total += a[index];
        } else {
            total -= a[index];
        }


    }
}
int main() {
    input();
    total = a[1];
    index = 2;
    ans = 0;
    Try(1);
    cout << ans;
}
