#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;
unsigned long long addMod(unsigned long long a, unsigned long long b) {

    return ((a%P) + (b%P)) % P;
}
int main() {

    unsigned long long a, b;
    cin >> a >> b;
    cout << addMod(a, b);;

    return 0;
}
