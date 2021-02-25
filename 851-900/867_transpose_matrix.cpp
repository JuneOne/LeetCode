/*
 * @see https://leetcode.com/problems/transpose-matrix
 * 
 * 矩阵转置
 * Input: matrix = [[1,2,3],[4,5,6]]
 * Output: [[1,4],[2,5],[3,6]]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return {};
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = matrix[j][i];
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6}};
    Solution s;
    vector<vector<int>> res = s.transpose(matrix);
    for (auto& row: res) {
        for (auto& ele: row) {
            cout << ele << ' ';
        }
        cout << endl;
    }

    return 0;
}
