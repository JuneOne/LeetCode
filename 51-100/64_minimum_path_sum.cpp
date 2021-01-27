/*
 * @see https://leetcode.com/problems/minimum-path-sum/
 * 
 * 从左上到右下（每次往下/往右走）的路径值最小
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 1 3 1
 * 1 5 1
 * 4 2 1
 * Output: 7(1->3->1->1->1)
 *
 * Constraints:
 * m = grid.length, n = grid[i].length
 * 1 <= m, n <= 200
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        for (int i = 1; i < column; i++) {
            grid[0][i] = grid[0][i-1] + grid[0][i];
        }
        for (int i = 1; i < row; i++) {
            grid[i][0] = grid[i-1][0] + grid[i][0];
            for (int j = 1; j < column; j++) {
                grid[i][j] = min(grid[i][j-1], grid[i-1][j]) + grid[i][j];
            }
        }
        return grid[row-1][column-1];
    }
};

int main()
{
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    Solution s;
    cout << s.minPathSum(grid) << endl;
}
