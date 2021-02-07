/*
 * @see https://leetcode.com/problems/non-decreasing-array/
 * 
 * 判断非递减数列（最多改变1个元素的值）
 * Input: nums = [4,2,3]
 * Output: true
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
    	int change = 0;
    	for (int i = 1; i < nums.size(); i++) {
    		if (nums[i] < nums[i-1]) {
    			change++;
	    		if (change > 1) {
    				return false;
    			}
    			if (i == 1 || nums[i] >= nums[i-2]) {
    				nums[i-1] = nums[i];
    			} else {
    				nums[i] = nums[i-1];
    			}
    		}
    	}
    	return true;
    }
};

int main()
{
    vector<int> nums = {1,3,2,3};
    Solution s;
	cout << s.checkPossibility(nums) << endl;
}
