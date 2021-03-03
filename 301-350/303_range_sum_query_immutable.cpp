/*
 * @see https://leetcode.com/problems/range-sum-query-immutable
 * 
 * 一维数组范围和
 * Input: nums = [-2,0,3,-5,2,-1], {i,j} = [0,2] 
 * Output: 1
 *
 * Note: 数组前缀和
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
class NumArray {
public:
    vector<int> sums;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};


int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0, 2) << endl;

    return 0;
}
