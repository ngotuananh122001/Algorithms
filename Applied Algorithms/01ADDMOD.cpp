#include <bits/stdc++.h>
using namespace std;

const long long N = 1e9 + 7;

unsigned long long smaller(unsigned long long a) {

    unsigned long long c = a / N;
    return a - N * c;
}

int main() {

    unsigned long long a, b;
    cin >> a >> b;

    a = smaller(a);
    b = smaller(b);

    cout << smaller(a+b);
}
