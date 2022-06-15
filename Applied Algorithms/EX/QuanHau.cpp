#include <bits/stdc++.h>
#define N 100
using namespace std;

int x[N] = {};
int n;
int cnt = 0;
void solution() {
    cnt++;
    cout << "method" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                cout << "x | ";
            else
                cout << "o | ";
        }
        cout << endl;
    }
}


bool check(int v, int k) {

    // Duyet tu hang 1 to k - 1
    // Phat hieu cac quan hau co an lan nhau khong
    int i = 1;
    while (i < k) {
        // Cung cot
        if (x[i] == v)
            return false;
        // cheo phai
        if (v + k - i <= n && x[i] == v + k - i)
            return false;
        // cheo trai
        if (v - k + i >= 1 && x[i] == v - k + i)
            return false;

        i++;
    }

    return true;
}

void Try(int k) {
    for (int v = 1;  v <= n; ++v) {
        if (check(v, k)) {
            x[k] = v;
            if (k == n)
                solution();
            else
                Try(k + 1);
        }
    }
}


int main() {
    cin >> n;
    Try(1);
    cout << "Number of way: " << cnt << endl;
}
