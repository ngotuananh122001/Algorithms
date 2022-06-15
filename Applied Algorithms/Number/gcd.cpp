#include <bits/stdc++.h>
using namespace std;

int gcd(int A, int B) {
    if (B == 0)
        return A;

    return gcd(B, A%B);
}

int main() {
    cout << gcd(2, 3);
}
