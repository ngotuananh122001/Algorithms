#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;
int n;
int a[MAXN];
int SC[MAXN];
int SL[MAXN];
bool BC[MAXN];
bool BL[MAXN];

/*
    SC[i]: là tổng trọng số của dãy con liên tiếp có tổng trọng số chẵn lớn nhất và kết thúc tại Ai
    SL[i]: là tổng trọng số của dãy con liên tieps có tổng trọng số lẻ lớn nhất và kết thúc tại Ai
    -> SC[i], và SL[i] có thể tồn tại hoặc không,
    đó là lý do cần mảng check BC[i] và BL[i]

*/
void input() {
    scanf("%d", &n);

    for (int i = 0;  i < n; i++) {
        scanf("%d", a + i);
    }
}

void maxEvenSeq() {
    if (a[0] % 2 == 0) {
        SC[0] = a[0]; BC[0] = true;
        BL[0] = false;
    } else {
        BC[0] = false;
        SL[0] = a[0]; BL[0] = true;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] % 2 == 0) {
            if (BC[i-1] == true) {
                SC[i] = max(a[i], a[i] + SC[i - 1]);
            } else {
                SC[i] = a[i];
            }
            BC[i] = true;

            if (BL[i - 1] == true) {
                SL[i] = a[i] + SL[i - 1];
                BL[i] = true;
            } else {
                BL[i] = false;
            }

            continue;
        }

        // a[i] is odd
        if (BL[i - 1] == true) {
            SC[i] = a[i] + SL[i - 1];
            BC[i] = true;
        } else {
            BC[i] = false;
        }

        if (BC[i - 1] == true) {
            SL[i] = max(a[i], a[i] + SC[i - 1]);
            BL[i] = true;
        } else {
            SL[i] = a[i];
            BL[i] = true;
        }
    }

    bool found = false;
    int i = 0;
    int ans;
    while (i < n && BC[i] == false) i++;
    if (i < n) {
        found = true;
        ans = SC[i];
    }

    for (; i < n; i++) {
        if (BC[i] == true) {
            ans = max(ans, SC[i]);
        }
    }

    if (found) {
        cout << ans << endl;
    } else {
        cout << "NOT_FOUND" << endl;
    }
}


int main() {
    input();
    maxEvenSeq();
}
