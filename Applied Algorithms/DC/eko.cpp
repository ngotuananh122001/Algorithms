#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 1e6+1;
long long height[MAXN];
long long n, m;

bool check(long long h) {
    long long sum = 0;
    for (long long i = n - 1; i >= 0; i--) {
        if (height[i] > h) {
            sum += height[i] - h;
            if (sum >= m)
                return true;
        }
    }
    return false;
}

long long bsearch(long long lo, long long hi) {
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    return lo - 1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long maxH = 0;
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        cin >> height[i];
        maxH = max(maxH, height[i]);
    }

    sort(height, height + n);
    cout << bsearch(0, height[n-1]);
}

