#include <bits/stdc++.h>
using namespace std;

int main() {

    unsigned long long a, b, a1, a2, b1, b2;
    cin >> a >> b;

    a1 = a / 10;
    a2 = a % 10;
    b1 = b / 10;
    b2 = b % 10;

    if (a1+b1+(a2+b2)/10 > 0) {
        cout << a1+b1+(a2+b2)/10;
        cout << (a2+b2)%10;
    } else
        cout << (a2+b2)%10;

    return 0;
}
