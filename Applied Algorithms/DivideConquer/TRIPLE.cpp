// https://codeforces.com/group/Ir5CI6f3FD/contest/273369/problem/I

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;
int n;
int k;
int a[5001];

int bsearch(int lo, int hi, int key) {
    int cnt = 0;
    int mid;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (a[mid] < key) {
            lo = mid + 1;
        } else if (a[mid] > key) {
            hi = mid - 1;
        } else {
            cnt++;
            int l = mid - 1;
            int r = mid + 1;
            while (l >= lo && a[l--] == key) cnt++;
            while (r <= hi && a[r++] == key) cnt++;
            break;
        }
    }

    return cnt;
}
int main() {
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    sort(a, a + n);

    int ans = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (k - a[i] - a[j] < 0)
                continue;
            int cnt = bsearch(j + 1, n - 1, k - a[i] - a[j]);
            ans += cnt;
        }
    }

    cout << ans << endl;

}
