#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
const int INF = 4e8;

int c[MAX][MAX];
bool visited[MAX] = {};

int cost; // cost so far
int cmin; //the smallest cost among all the hops to be traversed
int ans;

// n: number of cities
int m, n;


void Try(int lastNode, int k) {

    for (int v = 1; v <= n; v++) {
        if (!visited[v] && cost + c[lastNode][v] + cmin * (n-k+1) < ans) {
            visited[v] = true;
            cost += c[lastNode][v];
            if (k == n) {
                    ans = min(ans, cost + c[v][1]);
            } else {
                Try(v, k + 1);
            }

            cost -= c[lastNode][v];
            visited[v] = false;
        }
    }
}

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = INF;

    int u, v, c_uv;
    cmin = INF;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> c_uv;
        c[u][v] = c_uv;
        cmin = min(cmin, c_uv);
    }

    cost = 0;
    ans = INF;
    visited[1] = true;
    Try(1, 2);
    cout << ans << endl;
}
