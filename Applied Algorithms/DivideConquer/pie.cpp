#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+1;
const double PI = 3.14159265358979323846;
const double ESP = 1e-6;
double area[MAXN];
int n, f;

bool check(double volumn) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (int) (area[i] / volumn);
        if (cnt >= f)
            return true;
    }

    return false;
}
double bsearch(double lo, double hi) {
    while (hi - lo > ESP) {
        double mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    return lo;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &f);
        f++;
        int r;
        for (int i = 0; i < n; i++) {
            scanf("%d", &r);
            area[i] = PI * r * r;
        }

        sort(area, area + n);
        printf("%.6f\n", bsearch(0, area[n-1]));
    }
}

