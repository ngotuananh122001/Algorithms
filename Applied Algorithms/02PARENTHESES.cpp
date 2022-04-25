#include <bits/stdc++.h>
using namespace std;
#define MAX 100

bool isOpen(char c) {

    return c=='(' || c=='[' || c=='{';
}


bool match(char a, char b) {

    if (a=='(' && b==')' ||
        a=='[' && b==']' ||
        a=='{' && b=='}')
        return true;
    else
        return false;
}


int check(string st) {

    stack<char> S;
    int len = st.length();
    for (int i = 0; i < len; i++) {
        if (isOpen(st[i])) {
            S.push(st[i]);
            continue;
        }

        // now s[i] is close bracket
        if (S.empty())
            return 0;
        if (!match(S.top(), st[i]))
            return 0;
        S.pop();
    }

    if (!S.empty())
        return 0;
    return 1;
}
 int main() {
    int n;
    string st; // input string
    vector<string> inputs; // result array

    cin >> n;

    while (n > 0) {
        cin >> st;
        inputs.push_back(st);
        n--;
    }

    for (string st : inputs)
        cout << (check(st) ? 1 : 0) << endl;

    return 0;
 }
