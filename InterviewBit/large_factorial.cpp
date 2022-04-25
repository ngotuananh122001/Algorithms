/*
  @Desc:
    Given a number A. Find the fatorial of the number.



  @Note: Problem Constraints
    1 <= A <= 100



    Input Format
        First and only argument is the integer A.

    Output Format
        Return a string, the factorial of A.
  @Link:
    https://www.interviewbit.com/problems/large-factorial/

  @Notion
    https://ngotuananh.notion.site/Large-Factorial-3b0fbe05ff374d86a2cab1f0753c3903
*/

#include <iostream>
#include <sstream>
#include <string>

#define MAX_LEN 200
using namespace std;

string solve(int n) {
    int A[200] {};

    int len = 1;
    A[0] = 1;

    int tmp, carry = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= len; j++) {
            tmp = A[j] * i + carry;
            A[j] = tmp % 10;
            carry = tmp / 10;

            if (carry && j+1 == len)
                len++;
        }
    }

    stringstream ss;
    for (int i = len-1; i >= 0; i--)
        ss << A[i];

    return ss.str();


}


int main() {
    string ss = solve(100);
    cout << ss << endl;
    return 0;
}

