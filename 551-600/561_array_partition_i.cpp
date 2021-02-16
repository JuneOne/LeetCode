/*
 * @see https://leetcode.com/problems/array-partition-i
 * 
 * 将 2n 长度的数组拆分为 n 对，使得 min(ai, bi) 的和最大.
 * Input: nums = [1,4,3,2]
 * Output: 4 {(1,2),(3,4)} -> min(1,2)+min(3,4)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

int main()
{
    vector<int> nums = {1,4,3,2};
	Solution s;
	cout << s.arrayPairSum(nums) << endl;

    return 0;
}
