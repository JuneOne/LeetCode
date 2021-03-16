/*
 * @see https://leetcode.com/problems/spiral-matrix
 * 
 * 螺旋矩阵.
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int row = matrix.size(), col = matrix[0].size();
        vector<int> res;
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        int flag = 0;
        int i = 0, j = 0;
        for (int cnt = 0; cnt < row * col; cnt++) {
            res.push_back(matrix[i][j]);
            visit[i][j] = true;
            int i1 = i + direction[flag][0];
            int j1 = j + direction[flag][1];
            if (i1 < 0 || i1 >= row || j1 < 0 || j1 >= col || visit[i1][j1]) {
                flag = (flag + 1) % 4;
            }
            // 注意不能直接 i = i1, j = j1
            i += direction[flag][0];
            j += direction[flag][1];
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    vector<int> res = s.spiralOrder(matrix);
    for (auto const& val: res) {
        cout << val << ' ';
    }
    cout << endl;

    return 0;
}
