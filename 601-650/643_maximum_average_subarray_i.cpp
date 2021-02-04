/*
 * @see https://leetcode.com/problems/maximum-average-subarray-i/
 * 
 * 定长连续子数组的最大平均值
 * Input: nums = [1,12,-5,-6,50,3]
 * Output: 12.75
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += nums[i];
		}
		int max_sum = sum;
		for (int i = k; i < nums.size(); i++) {
			sum += (nums[i] - nums[i-k]);
			max_sum = max(max_sum, sum);
		}
		return (double)max_sum / k;
    }
};

int main()
{
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    Solution s;
	cout << s.findMaxAverage(nums, k) << endl;
}
