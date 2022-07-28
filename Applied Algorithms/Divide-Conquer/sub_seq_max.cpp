#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

int MaxLeftMid(vector<int> A, int i, int j) {
    int maxLM = A[j];
    int s = 0;
    for (int k = j; k >= i; k--) {
        s += A[k];
        maxLM = max(maxLM, s);
    }

    return maxLM;
}

int MaxRightMid(vector<int> A, int i, int j) {
    int maxRM = A[i];
    int s = 0;
    for (int k = i; k <= j; ++k) {
        s += A[k];
        maxRM = max(maxRM, s);
    }

    return maxRM;
}

int SubSeqMax(vector<int> A, int left, int right) {
    if (left == right) {
        return A[left];
    }

    int mid = left + (right - left) / 2;

    int wL = SubSeqMax(A, left, mid);
    int wR = SubSeqMax(A, mid + 1, right);
    int wM = MaxLeftMid(A, left, mid) + MaxRightMid(A, mid + 1, right);

    return max(wL, max(wM, wR));
}

int main() {
    vector<int> A = {-16, 7, -3, 0, -1, 5, -4};
    cout << SubSeqMax(A, 0, A.size() - 1);
    return 0;
}
