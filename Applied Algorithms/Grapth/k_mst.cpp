#include <iostream>
using namespace std;

struct Node {
    int u;
    int v;
};
int main() {
    Node x = {1, 2};
    cout << x.u << " | " << x.v << endl;
}
