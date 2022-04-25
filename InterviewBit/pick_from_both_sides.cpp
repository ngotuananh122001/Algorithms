/*
  @Problem Description
    Given an integer array A of size N.
    You can pick B elements from either left or right end of the array A to get maximum sum.
    Find and return this maximum possible sum.

  @NOTE: Suppose B = 4 and array A contains 10 elements then
    You can pick first four elements or can pick last four elements
    or can pick 1 from front and 3 from back etc . you need to return the maximum possible sum of elements you can pick.

  @Link
    https://www.interviewbit.com/problems/pick-from-both-sides/
*/

#include <iostream>
#include <vector>
using namespace std;

int Solve(vector<int> &A, int B) {
    int n = A.size();

    int ans = 0;
    for (int i = 0; i < B; i++)
        ans += A[i];

    int l = B; // Số phần tử bên trái
    int r = 0; // Số phần tử bên phải
    int tmp = ans;

    while (l >= 0) {
        tmp = tmp - A[l-1] + A[n-1-r]; // Bớt một phần tử bên trái, thêm một phần tử bên phải
        ans = max(ans, tmp);
        l--;
        r++;
    }

    return ans;
}

int main() {
    vector<int> A;
    A.assign({5, -2, 3 , 1, 2});
    cout << Solve(A, 3);

    /*
      @Kỳ vọng: 8
      @Explanation
        Pick element 5 from front and element (1, 2) from back so we get 5 + 1 + 2 = 8
    */
    return 0;
}
