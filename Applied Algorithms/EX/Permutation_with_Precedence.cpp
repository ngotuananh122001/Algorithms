#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int n, k;
int numOfResult;
// e[i] chứa tập các đỉnh đứng trước đỉnh i
vector<int> e[N];
int X[N];
bool visited[N];

bool check(int i) {
    if (visited[i]) {
        return false;
    }

    for (auto j : e[i]) {
        if (!visited[j]) {
            return false;
        }
    }

    return true;
}

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        if (check(i)) {
            X[k] = i;
            visited[i] = true;

            if (k == n) {
                    numOfResult++;
                for (int j = 1; j <= n; ++j)
                    cout << X[j] << " ";
                cout << endl;
            } else {
                Try(k + 1);
            }

            visited[i] = false;
        }
    }
}
int main() {
    cin >> n >> k;

    int a, b;
    while (k--) {
        cin >> a >> b;
        e[b].push_back(a);
    }

    numOfResult = 0;
    memset(visited, 0, sizeof(visited));
    Try(1);
    cout << numOfResult << endl;
    return 0;
}

