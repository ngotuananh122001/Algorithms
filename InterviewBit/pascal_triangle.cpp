/*
    Kth Row of Pascal's Triangle
    Input : k = 3
    Return : [1,3,3,1]

    Note: k is 0 based. k = 0, corresponds to the row [1].
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> Solve(int k) {
    vector<int> ans; // answer

    // based
    ans.assign({1}); // [1]

    if (k > 0) {
        for (int i = 1; i <= k; i++) {
            // Hàng i có i+1 phần tử,
            // Phần tử đầu và cuối là 1
            // now tính i-1 phần tử ở giữa
            for (int j = 0; j < i-1; j++) {
                ans[j] = ans[j] + ans[j+1];
            }

            // Thêm phần tử 1 vào đầu và cuối
            ans.assign(ans.begin(), ans.begin()+i-1);
            ans.push_back(1);
            ans.insert(ans.begin() , 1);
        } // lặp lại cho tới hàng thứ k
    }

    return ans;
}


int main() {
    vector<int> result = Solve(4);
    for (int a : result)
        cout << a << " ";
    return 0;
}
