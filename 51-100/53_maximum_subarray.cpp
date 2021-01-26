/*
 * @see https://leetcode.com/problems/maximum-subarray/
 * 
 * 连续最大子串和: dp[i]表示以i结尾的最大子串和
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6([4,-1,2,1])
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int max_res = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            max_res = max(max_res, dp[i]);
        }
        return max_res;
    }
};

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(nums) << endl;
}
