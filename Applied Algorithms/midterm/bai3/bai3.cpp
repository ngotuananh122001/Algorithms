#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int g[N][N];
int n;
int r, c;
int maxSum = INT_MIN;
int currentSum = 0;
void input() {
    scanf("%d%d%d", &n, &r, &c);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
}

// |x| + |y| = 3;
int xCor[] = {2, 1, -1, -2, -2, -1, 1, 2};
int yCor[] = {1, 2, 2, 1, -1, -2, -2, -1};

// chess[i][j] = k; o vi tri (i, j) duoc di qua o buoc thu k
int chess[N][N];

bool checkMove(int next_x, int next_y) {
    return next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= n && chess[next_x][next_y] == -1;
}


int util(int x, int y, int movei) {
    int next_x;
    int next_y;
    for (int k = 0; k < 8; k++) {
        next_x = x + xCor[k];
        next_y = y + yCor[k];

        if (checkMove(next_x, next_y)) {
            chess[next_x][next_y] = 1;
            currentSum += g[next_x][next_y];

            if (maxSum < currentSum) {
                maxSum = currentSum;
            }

            util(next_x, next_y, movei + 1);

            chess[next_x][next_y] = -1;
            currentSum -= g[next_x][next_y];
        }
    }

    return 0;
}
void solve() {

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            chess[i][j] = -1;

    chess[r][c] = 1;
    currentSum += g[r][c];
    util(r, c, 1);

	if (maxSum == INT_MIN)
		cout << g[r][c];
	else
    	cout << maxSum << endl;
}


int main() {
// 	freopen("3-input.txt", "r", stdin);
	input();
    solve();
    return 0;
}

