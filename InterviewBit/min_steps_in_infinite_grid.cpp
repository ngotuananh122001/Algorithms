/*
  @Link: https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
  @Desc
    You are in an infinite 2D grid
    where you can move in any of the 8 directions

     (x,y) to
        (x-1, y-1),
        (x-1, y)  ,
        (x-1, y+1),
        (x  , y-1),
        (x  , y+1),
        (x+1, y-1),
        (x+1, y)  ,
        (x+1, y+1)
    You are given a sequence of points and
    the order in which you need to cover the points..
    Give the minimum number of steps in which you can achieve it.
    You start from the first point.

  @Example
    A = [0, 1, 1]
    B = [0, 1, 2]
    output: 2
    // Explanation
    Given three points are: (0, 0), (1, 1) and (1, 2).
    It takes 1 step to move from (0, 0) to (1, 1).
    It takes one more step to move from (1, 1) to (1, 2).
*/

#include <iostream>
#include <vector>
using namespace std;


/*
    Vì các điểm cần đi qua được sắp thứ tự, nên
    ta sẽ tìm số bước để đi từ điểm 1 sang điểm 2,
    điểm 2 sang 3, so on..
    -> Tính tổng ra kết quả


    Số bước cần thiết để đi từ điểm A(x1, y1) tới B(x2, y2);
    Ví dụ (1,1) tới (3,4) ( kí hiệu là ^)

    * * ^
    * * *
    * * *
    ^ * *

    Con đường ngắn nhất là đi theo đường chéo, rồi đi thẳng hoặc ngang
    (1,1) -> (2,2) -> (3,3) -> (3,4) => vậy cần 3 bước đi

    Mặt khác:
        Số bước đi trên đường chéo là 2 [(2,2), (3,3)]
        trùng với độ dài hv 2*2 (đường chéo tương ứng)

    Tóm lại số bước cần thiết chính là cạnh dài hơn của hình tứ giác kia
    abs(y2-y1) or abs(x2-x1)
*/
class Solution {
    public:
        int coverPoints(vector<int> &A, vector<int> &B) {
            int ret = 0;

            for (int i = 0; i < A.size() - 1; i++) {
                ret += stepsForMove(A[i], B[i], A[i+1], B[i+1]);
            }

            return ret;
        }
    private:
        int stepsForMove(int x1, int y1, int x2, int y2) {
            if (abs(y2-y1) > abs(x2-x1))
                return abs(y2-y1);
            else
                return abs(x2-x1);
        }
};


int main() {
    vector<int> A = {0, 1, 3};
    vector<int> B = {0, 1, 4};

    Solution s;
    cout << s.coverPoints(A, B); // Expected: 4
    cout << "\n";
    return 0;
}












