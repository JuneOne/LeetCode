/*
 * @see https://leetcode.com/problems/3sum-closest
 *
 * 最接近 target 的三数之和（可以假设只有一个解）
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2 (-1 + 2 + 1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int resSum = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > target && resSum >= target) {
                break;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(resSum - target)) {
                    resSum = sum;
                }
                if (sum <= target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return resSum;
    }
};

int main()
{
    vector<int> nums = {-1,2,1,-4};
    Solution s;
    cout << s.threeSumClosest(nums, 1) << endl;

    return 0;
}

