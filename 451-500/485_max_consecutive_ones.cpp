/*
 * @see https://leetcode.com/problems/max-consecutive-ones/
 * 
 * 最大连续1的个数
 * Input: [1,1,0,1,1,1]
 * Output: 3
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        for (int left = -1, right = 0; right < nums.size(); right++) {
            if (nums[right] == 1) {
                maxLen = max(right - left, maxLen);
            } else {
                left = right;
            }
        }
        return maxLen;
    }
};

int main()
{
    vector<int> nums = {1,1,0,1,1,1};
    Solution s;
    cout << s.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
