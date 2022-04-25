/*
  @title: Majority Element
  @desc
     A majority element in an array A[] of size n is an element
     that appears more than n/2 times
     (and hence there is at most one such element)

  @Note
    Intput : {3, 3, 4, 2, 4, 4, 2, 4, 4}
    Output: 4
    The frequency of 4 is 5 which is greater
    than the half of the size of the array size
  @Link
   https://www.interviewbit.com/problems/majority-element/

*/


#include <iostream>
#include <vector>
using namespace std;

// Thuật toán Moore’s Voting

int majorityElement(const vector<int> &A) {
    int index = -1; // lính canh, majority index
    int cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        if (cnt == 0) {
            index = i;
        }

        A[i] == A[index] ? cnt++ : cnt--;
    }

    cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == A[index])
            cnt++;
    }

    if (cnt > A.size()/2)
        return A[index];
    return -1; // Khong ton tai
}

int main() {
    vector<int> nums = { 1, 1, 1, 1, 2, 3, 4 };

    int majority = majorityElement(nums);

    cout << "The majority element is : " << majority; // expected: 1
    return 0;
}
