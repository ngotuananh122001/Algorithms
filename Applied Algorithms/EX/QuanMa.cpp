#include <bits/stdc++.h>
using namespace std;

const int N = 6;

// |x| + |y| = 3;
int xCor[] = {2, 1, -1, -2, -2, -1, 1, 2};
int yCor[] = {1, 2, 2, 1, -1, -2, -2, -1};

// chess[i][j] = k; o vi tri (i, j) duoc di qua o buoc thu k
int chess[N][N];

bool checkMove(int next_x, int next_y) {
    return next_x >= 0 && next_x < 8 && next_y >= 0 && next_y < 8 && chess[next_x][next_y] == -1;
}


int util(int x, int y, int movei) {
    if (movei == N * N && x == 0 && y== 0) {
        return 1;
    }

    int next_x;
    int next_y;
    for (int k = 0; k < 8; k++) {
        next_x = x + xCor[k];
        next_y = y + yCor[k];

        if (checkMove(next_x, next_y)) {
            chess[next_x][next_y] = movei;
            if (util(next_x, next_y, movei+1) == 1) {
                return 1;
            }
            else {
                chess[next_x][next_y] = -1;
            }

        }
    }

    return 0;
}
void solve() {

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            chess[i][j] = -1;

    chess[0][0] = 0;
    int ret = util(0, 0, 1);

    if (ret) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << chess[i][j] << ' ';
        }
    } else {
        cout << "Not found\n";
    }
}


int main() {
    solve();
    return 0;
}
