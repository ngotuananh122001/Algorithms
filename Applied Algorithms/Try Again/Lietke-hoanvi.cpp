#include <bits/stdc++.h>
using namespace std;

#define N 100

int n;
int x[N];
bool visited[N];

bool check(int v, int k) {

    // xac dinh ung vien v
    // co phu hop cho thanh phan x[k]
    return !visited[v];
}


void solution() {

    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

void Try(int k) {

    for (int v = 1; v <= n; v++) {
        if (check(v, k)) {
            x[k] = v;
            visited[v] = true;
            if (k == n) {
                solution();
            } else Try(k+1);

            visited[v] = false;
        }
    }
}


int main() {

    n = 3;
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    Try(1);
}
