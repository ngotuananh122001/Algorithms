#include <bits/stdc++.h>
#define NIL -1
#define MAX 100
using namespace std;


int lookup[MAX];

void init() {
    for (int i = 1; i <= MAX; ++i)
        lookup[i] = NIL;
}


int fibo(int n) {
    if (lookup[n] != NIL)
        return lookup[n];

    // solve subproblem without answer
    if (n <= 2)
        lookup[n] = 1;
    else
        lookup[n] = fibo(n - 1) + fibo(n - 2);

    return lookup[n];
}


int main() {

    int n = 1;
    do {
        init();
        cout << "Fibo(" << n << ") = " << fibo(n) << endl;
        cout << "n = ";
    } while (cin >> n);
}
