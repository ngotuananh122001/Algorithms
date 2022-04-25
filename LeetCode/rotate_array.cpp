#include <iostream>
#include <vector>
using namespace std;


void reverseList(vector<int>& A, int start, int end) {
    int l = start;
    int r = end;
    while (l < r) {
        swap(A[l], A[r]);
        l++;
        r--;
    }
}

/*
    @title: Rotate Right
    @desc: Given an array, rotate the array to the right by k steps,
            where k is non-negative.
    @link: https://leetcode.com/problems/rotate-array/

*/


void rotate(vector<int>& nums, int k) {
    int n = nums.size();

    int midpoint = n-k;
    reverseList(nums, 0, midpoint-1);
    reverseList(nums, midpoint, n-1);
    reverseList(nums, 0, n-1);
}
int main() {
    vector<int> nums = {1,2,3,4,5};

    rotate(nums, 2);

    for (auto x : nums)
        cout << x << " ";
}
