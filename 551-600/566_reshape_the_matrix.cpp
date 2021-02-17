/*
 * @see https://leetcode.com/problems/reshape-the-matrix
 * 
 * 将矩阵(m*n)重塑成矩阵(r*c)
 * Input: nums = [[1,2],[3,4]], r = 1, c = 4
 * Output: [[1,2,3,4]]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() == 0) {
            return nums;
        }
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < m * n; i++) {
            res[i / c][i % c] = nums[i / n][i % n];
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> nums = {{1,2},{3,4}};
    int r = 1, c = 4;
	Solution s;
	vector<vector<int>> res = s.matrixReshape(nums, r, c);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
