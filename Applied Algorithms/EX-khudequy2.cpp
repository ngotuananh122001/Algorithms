#include <bits/stdc++.h>
using namespace std;
#define N 100
int n;
int x[N];
bool visted[N];

struct Node {

    int index;
    int value;
    int parent;
    int nbChildrent;
    Node(int _id, int _value, int _parent, int _npChildrent) {
        index = _id;
        value = _value;
        parent = _parent;
        nbChildrent = _npChildrent;
    }
};

void solution() {

    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}



void solve() {
    vector<Node> S;
    S.push_back(Node(0,0,-1,-1));

    int cnt = 0;
    while (S.size() > 0) {


        int t = S.size() - 1;
        Node e = S[t]; // element on top
        x[e.index] = e.value;
        visted[e.value] = true;

        if (e.index == n){

             solution();

             // dinh k co node con
             while (S.size() > 0 && S[S.size() - 1].nbChildrent == 0 ) {
                Node e1 = S[S.size() - 1];
                visted[e1.value] = false;
                int par = e1.parent;
                S.pop_back();
                S[par].nbChildrent =- 1;

                if (par != S.size() - 1) break;

            }
        } else {

            for(int v = n; v >= 1; v--)
                if (!visted[v]) {
                    S.push_back(Node(e.index + 1, v, t, 0));
                    S[t].nbChildrent += 1; // tang so phan tu con cua node hien tai
                }


        }

        // quay lui


    }
}

int main() {

    n = 3;
    for (int i = 1; i <= n; i++) visted[i] = false;
    solve();
}















