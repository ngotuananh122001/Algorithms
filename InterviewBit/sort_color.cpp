/*
  @desc: Sort Colors
    Given an array nums with n objects colored red, white, or blue, sort them in-place
    so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

  @Note
    You must solve this problem without using the library's sort function.

  @Expected
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

  @Link
    https://leetcode.com/problems/sort-colors/
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:
        void sortColors(vector<int>&);
};

void Solution::sortColors(vector<int>& nums) {
    int pivot = 1;
    int n = nums.size();

    // Đưa các số 0 về đầu
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] < pivot) {
            swap(nums[i], nums[l]);
            l++;
        }
    }

    // Đưa các số 2 về cuối
    int r = n-1;
    for (int i = n-1; i >= 0; i--) {
        if (nums[i] > pivot) {
            swap(nums[i], nums[r]);
            r--;
        }

        if (nums[i] < pivot)
            break;
    }
}

int main() {
    vector<int> nums = {2,0,2,1,1,0};

    Solution s;
    s.sortColors(nums);

    for (auto x : nums)
        cout << x << " ";
    return 0;
}
