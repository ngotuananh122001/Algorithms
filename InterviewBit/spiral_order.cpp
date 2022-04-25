/*
    @Desc:

    Input: [
        [ 1, 2, 3 ],
        [ 4, 5, 6 ],
        [ 7, 8, 9 ]
    ]
    You should return
        [1, 2, 3, 6, 9, 8, 7, 4, 5]
    @Link:
        https://www.interviewbit.com/problems/spiral-order-matrix-i/


    @Solve:
        https://ngotuananh.notion.site/Sprial-Order-Matrix-665aa0e58333463ea4f2011c49bfff59

*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
    // direction: 0 (right), 1 (down), 2 (left), 3 (up);

    /*
  T->   ---- right ------
        |               |
       up               down
        |               |
  B ->  |---- left ------

        ^               ^
        |               |
        L               R
    */
    int dir = 0;

    int T = 0; // for topmost
    int B = A.size() - 1; // for bottom
    int L = 0; // for leftmost
    int R = A[0].size() - 1;

    vector<int> ret; // for result vector

    while (T <= B && L <= R) {
        if (dir == 0) {
            for (int i = L; i <= R; i++)
                ret.push_back(A[T][i]);

            T++;
            dir = 1;
        } else if (dir == 1) {
            for (int i = T; i <= B; i++)
                ret.push_back(A[i][R]);
            R--;
            dir = 2;
        } else if (dir == 2) {
            for (int i = R; i >= L; i--)
                ret.push_back(A[B][i]);
            B--;
            dir = 3;
        } else {
            for (int i = B; i >= T; i--)
                ret.push_back(A[i][L]);
            L++;
            dir = 0;
        }

    }

    return ret;
}

int main() {
    vector<vector<int> > input = {{1,2,3}, {4,5,6}, {7,8,9} };

    for (auto x : spiralOrder(input))
        cout << x << " ";

    cout << "\n";
    return 0;
}
