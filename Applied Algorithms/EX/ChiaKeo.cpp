#include <iostream>
using namespace std;

#define N 100

int x[N] = {};
int n; // so em be
int m; // so keo
int m0; // so keo con lai sau moi lan chia


void solution() {

    for (int i = 1; i <= n; i++)
        cout << x[i] << " | ";
    cout << endl;
}


bool check(int v, int k) {

    return true;
}


void Try(int k) {

    if (k == n) {

        x[k] = m0;
        solution();
        return;
    }

    for (int v = 1; m0 - v >= n - k; v++) {
        if (check(v, k)) {
            x[k] = v;
            m0 -= v;
            Try(k+1);
            m0 += v;
        }
    }
}


int main() {

    cin >> n >> m;
    m0 = m;
    Try(1);
}
