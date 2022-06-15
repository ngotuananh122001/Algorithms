#include <bits/stdc++.h>
using namespace std;

#define N 20

int x[N];
int cell[N][N];
int bCol[2*N] = {};
int bDiagLeft[2*N] = {};
int bDiagRight[2*N] = {};

// n kich thuoc board vuong
// m tong so hole
int n, m;
int numOfSolution;


void solution() {

    numOfSolution++;
}


// make sure the queens don't eat each other
bool check(int v, int k) {

    // Hole
    if (cell[k][v] == 1)
        return false;

    // Check row 1 to k - 1
    if (bCol[v] || bDiagLeft[k-v] || bDiagRight[k+v])
        return false;

    return true;
}


// Find the position of the queen in the K'th row
void Try(int k) {

    for (int v = 1; v <= n; v++) {
        if (check(v, k)) {
            x[k] = v;
            bCol[v] = 1;
            bDiagLeft[k-v] = 1;
            bDiagRight[k+v] = 1;
            if (k == n) solution();
            else Try(k+1);
            bCol[v] = 0;
            bDiagLeft[k-v] = 0;
            bDiagRight[k+v] = 0;
        }
    }
}


int main() {

    int p, q;

    while (1) {

        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cell[i][j] = 0;
        }

        for (int i = 1; i <= m; ++i) {
            cin >> p >> q;
            cell[p][q] = 1;
        }

        numOfSolution = 0;
        Try(1);
        cout << numOfSolution << endl;;
    }
}
