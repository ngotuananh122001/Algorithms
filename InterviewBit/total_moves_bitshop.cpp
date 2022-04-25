/*
  @title: Total Moves For Bishop!
  @desc
    Given the position of a Bishop (A, B) on an 8 * 8 chessboard.
    Your task is to count the total number of squares
    that can be visited by the Bishop in one move.

    The position of the Bishop
    is denoted using row and column number of the chessboard.

  @Note
    1 <= A, B <= 8
  @Link
    https://www.interviewbit.com/problems/total-moves-for-bishop

*/


#include <iostream>
using namespace std;

class Solution {
    public:
        int solve(int, int);
};

int Solution::solve(int A, int B) {
    int ans = 0;

    // Chọn mốc (1,1) là điểm dưới góc trái

    // top right
    ans += min(8-A, 8-B);

    // top left
    ans += min(8-A, B-1);

    // bottom right
    ans += min(A-1, 8-B);

    // bottom left
    ans += min(A-1, B-1);

    return ans;

}

int main() {
    Solution s;
    cout << s.solve(4,4); // expected: 13
}
