#include <bits/stdc++.h>
#define MAX 100
#define NIL -1
using namespace std;

int A[MAX] = {-2, -3, 4, -1, -2, 1, 5, -3};

int solve(int i) {
    if (i == 0)
        return A[i];

    return max(A[i], A[i] + solve(i - 1));
}
int main() {

    cout << solve(7) << endl;
}
