/*
  @desc
    Find the contiguous subarray within an array, A of length N which has the largest sum.


  @expecte
    Input 1: A = [1, 2, 3, 4, -10]
    Output 1: 10
    Explanation 1:
        The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

    Input 2: A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    Output 2: 6
    Explanation 2:
        The subarray [4,-1,2,1] has the maximum possible sum of 6.

  @Note

  @Link
    https://www.interviewbit.com/problems/max-sum-contiguous-subarray
    ans: https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/?ref=lbp
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxSubArray(const vector<int> &);
};


int maxSub(const vector<int> &A, int i, int j) {
    if (i==j)
        return A[i];

    int m = (i+j) / 2;
    int maxLeftSub = maxSub(A, i, m);
    int maxRightSub = maxSub(A, m+1, j);

    /*Maximum subarray sum such that the subarray
       crosses the midpoint */
    // Tìm dãy con lớn nhất, bắt đầu bên trái, kết thúc ở điểm bên phải
    // Bat dau tim day con o giua
    int leftSum = A[m];
    int sum = 0;
    for (int k = m; k >= i; k--) {
        sum += A[k];
        leftSum = max(leftSum, sum);
    }

    int rightSum = A[m+1];
    sum = 0;
    for (int k = m+1; k <= j; k++) {
        sum += A[k];
        rightSum = max(rightSum, sum);
    }

    int maxCross = leftSum + rightSum;
    // Ket thuc tim day con o giua


    return max(max(maxLeftSub, maxRightSub), maxCross);
}

int Solution::maxSubArray(const vector<int> &A) {
    int ans = maxSub(A, 0, A.size() - 1);

    return ans;
}

int main() {
    vector<int> nums = {-2, -5, 6, -2, -3, 1, 5, -6};

    // 6, -2, -3, 1, 5 is subarray
    Solution s;
    cout << s.maxSubArray(nums); // expected : 7 = 6 + -2 + -3 + 1 + 5
    return 0;
}
