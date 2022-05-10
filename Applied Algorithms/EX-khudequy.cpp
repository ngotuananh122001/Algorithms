#include <bits/stdc++.h>
using namespace std;

int n;
int x[100];


struct Node {

    int id;
    int value;

    Node(int _id, int _value) {
        id = _id;
        value = _value;
    }
};

void solution() {

    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}


void solve() {

    vector<Node> S;
    S.push_back(Node(0,0));
    while (!S.empty()) {

        int idx = S.size() - 1;
        Node e = S[idx]; // element on top of the stack S
        x[e.id] = e.value;
        S.pop_back();
        if (e.id == n) {
            solution();
        } else {
            S.push_back(Node(e.id+1, 1));
            S.push_back(Node(e.id+1, 0));
        }
    }
}

int main() {

    n = 3;
    solve();
    return 0;
}
