/*
 * @see https://leetcode.com/problems/longest-increasing-subsequence
 * 
 * 最长上升子序列
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4([2,3,7,101])
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // dp[i]表示以第i个元素结尾的LIS长度
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int max_res = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            max_res = max(max_res, dp[i]);
        }
        return max_res;
    }

    /*
     * stack[i]代表长度为i+1的上升子序列最后一个元素的最小可能取值.
     *
    int lengthOfLIS(vector<int>& nums) {
        vector<int> stack;
        stack.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > stack.back()) {
                stack.push_back(nums[i]);
            } else {
                // O(N)，因为 stack 内部是有序的，可以优化为 O(logN)
                for (int j = 0; j < stack.size(); j++) {
                    // 严格递增子序列，要用大于等于
                    if (stack[j] >= nums[i]) {
                        stack[j] = nums[i];
                        break;
                    }
                }
                // O(logN)优化
                // auto iter = lower_bound(stack.begin(), stack.end(), nums[i]);
                // *iter = nums[i];
            }
        }
        return stack.size();
    }
     */
};

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution s;
    cout << s.lengthOfLIS(nums) << endl;
}
