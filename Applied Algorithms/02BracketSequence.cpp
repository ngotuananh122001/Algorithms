#include <bits/stdc++.h>
using namespace std;


bool isOpen(char c) {

    return c=='(' || c=='[';
}


bool match(char a, char b) {

    if (a=='(' && b==')' ||
        a=='[' && b==']')
        return true;
    else
        return false;
}


int check(const char* st, int l, int r) {

    stack<char> S;
    int n = 0;
    for (int i = l; i <= r; i++) {
        if (isOpen(st[i])) {
            S.push(st[i]);
            n++;
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

    return n;
}

void find(string st) {

    int res = 0;
    int x = -999;
    int len = st.length();
    int l = 0, r;
    int ll = 0, rr = 0;
    while (l < len) {
        r = len-1;
        for (; r > l; r--) {
            int n = check(st.c_str(), l, r);
            if (n) {
                if (n >= x) {
                    x = n;
                    res++;
                    ll = l;
                    rr = r;
                }
            }
        }

        l++;
    }

    cout << res << endl;
    if (!res)
        return;
    for (int i = ll; i <= rr; i++)
        cout << st[i];
}


int main() {

    string st;
    cin >> st;
    find(st);
    return 0;
}
