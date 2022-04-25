/*
  @Problem Description
    Add One To Number

  @NOTE:
    Input 1: [1, 2, 3]
    Output 1: [1, 2, 4]



  @Link
    https://www.interviewbit.com/problems/add-one-to-number/

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> plusOne(vector<int> &A) {
    int n = A.size();

    A[n-1] += 1;
    int carry = A[n-1] / 10; // 0 or 1
    A[n-1] = A[n-1] % 10;

    for (int i = n-2; i >= 0; i--) {
        if (carry == 1) {
            A[i] += 1;
            carry = A[i] / 10;
            A[i] = A[i] % 10;
        }
    }

    if (carry == 1) {
        A.insert(A.begin(), 1);
    }

    while(A[0] == 0) A.erase(A.begin());
    return A;
}

int main() {
    vector<int> nums = {2, 5, 6, 8, 6, 1, 2, 4, 5};

    vector<int> ans = plusOne(nums);
    for (auto x : ans)
        cout << x << " ";

    cout << endl;

    nums.assign({9,9,9,9,9});
    ans = plusOne(nums);
    for (auto x : ans)
        cout << x << " ";
}
