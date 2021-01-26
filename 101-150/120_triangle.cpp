/*
 * @see https://leetcode.com/problems/triangle/
 * 
 * 从上往下（每次往下/往右下走）的路径值最小
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 *    2
 *   3 4
 *  6 5 7
 * 4 1 8 3
 * Output: 11(2->3->5->1)
 *
 * Constraints:
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 *
 * Note: 自底向上可以避免边界判断
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
            }
        }
        return triangle[0][0];
    }

    /*
     * @see https://leetcode.com/problems/triangle/discuss/38730/DP-Solution-for-Triangle
     *
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> minlen(triangle.back());
        for (int layer = triangle.size() - 2; layer >= 0; layer--) // For each layer
        {
            for (int i = 0; i <= layer; i++) // Check its every 'node'
            {
                // Find the lesser of its two children, and sum the current value in the triangle with it.
                minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
            }
        }
        return minlen[0];
    }
     */
};

int main()
{
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution s;
    cout << s.minimumTotal(triangle) << endl;
}
