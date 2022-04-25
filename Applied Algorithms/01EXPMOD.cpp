#include <bits/stdc++.h>
using namespace std;

const unsigned long long P = 1e9 + 7;

// Tham khao Fermat nho: https://vi.wikipedia.org/wiki/%C4%90%E1%BB%8Bnh_l%C3%BD_nh%E1%BB%8F_Fermat
// a^n = a^(P*x+k) = a^(x+k) mod P, P la so nguyen to
unsigned long long extract(unsigned long long n) {

    unsigned long long x = n / P;
    unsigned long long k = n % P;
    return x + k;
}

long long binpow(long long a, long long b) {
    a = a % P;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

unsigned long long expMod(unsigned long long a, unsigned long long n) {

    if (extract(n) < P)
        return binpow(a, n);
    return expMod(a, extract(n));
}



int main() {
    unsigned long long a, n;
    cin >> a >> n;

    cout << expMod(a, n);
}
