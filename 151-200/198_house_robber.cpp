/*
 * @see https://leetcode.com/problems/house-robber/
 * 
 * 不能选相邻的两个
 * Input: nums = [2,7,9,3,1]
 * Output: 12(nums[0] + nums[2] + nums[4])
 *
 * Note: 背包问题
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n, 0);
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
};

int main()
{
    vector<int> nums = {2,7,9,3,1};
    Solution s;
    cout << s.rob(nums) << endl;
}
