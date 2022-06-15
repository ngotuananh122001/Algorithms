#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int tmp[MAXN];
// Merge sort
void mSort(vector<int> &A, int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = (l + r) / 2;
    mSort(A, l, mid);
    mSort(A, mid + 1, r);

    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid || j <= r) {
        if (i > mid) {
            // bên trái không còn phần tử nào
            tmp[k++] = A[j++];
        } else if (j > r) {
            // bên phải không còn phần tử nào
            tmp[k++] = A[i++];
        } else if (A[i] < A[j]) {
            // phần tử bên trái nhỏ hơn phần tử bên phải
            tmp[k++] = A[i++];
        } else {
            // phần tử bên phải nhỏ hơn
            tmp[k++] = A[j++];
        }
    }

    k = 0;
    for (i = l; i <= r; ++i) {
        A[i] = tmp[k++];
    }

}


int main() {
    vector<int> A = {1, 7, 9, 6 ,2};
    mSort(A, 0, A.size() - 1);
    for (int n : A) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
