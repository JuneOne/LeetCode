/*
 * @see https://leetcode.com/problems/flipping-an-image
 * 
 * 水平翻转 + 反转 0/1 数组
 * Input: [[1,1,0],[1,0,1],[0,0,0]
 * Output: [[1,0,0],[0,1,0],[1,1,1]]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = 1 - A[i][n - j - 1];
            }
        }
        return res;
    }

    /**
     * two pointers.
     *
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size(); // A.length = A[0].length()
        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while (left < right) {
                // {left, right} 为 {0,1},{1,0} 时，结果不变
                if (A[i][left] == A[i][right]) {
                    A[i][left] ^= 1;
                    A[i][right] ^= 1;
                }
                left++; right--;
            }
            if (left == right) {
                A[i][left] ^= 1;
            }
        }
        return A;
    }
     */
};

int main()
{
    vector<vector<int>> matrix = {{1,1,0},{1,0,1},{0,0,0}};
    Solution s;
    vector<vector<int>> res = s.flipAndInvertImage(matrix);
    for (auto& row: res) {
        for (auto& ele: row) {
            cout << ele << ' ';
        }
        cout << endl;
    }

    return 0;
}
