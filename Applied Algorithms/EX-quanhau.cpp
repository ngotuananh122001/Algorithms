#include <bits/stdc++.h>
using namespace std;

#define N 100

int x[N];
int n; // row number
int cnt;


void solution() {

    cnt++;
}


// make sure the queens don't eat each other
bool check(int v, int k) {

    int i = 1;

    // lop each row k-i
    while (i < k) {
        if (x[k-i] == v) return false;
        if (v - i >= 1 && x[k - i] == v - i) return false;
        if (v + i <= n && x[k - i] == v + i) return false;

        i++;
    }

    return true;
}


// Find the position of the queen in the K'th row
void Try(int k) {

    for (int v = 1; v <= n; v++) {
        if (check(v, k)) {
            x[k] = v;
            if (k == n) solution();
            else Try(k+1);
        }
    }
}


int main() {

    cin >> n;
    cnt = 0;
    Try(1);
    cout << "Ans = " << cnt << endl;
}
