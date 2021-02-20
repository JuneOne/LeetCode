/*
 * @see https://leetcode.com/problems/degree-of-an-array
 * 
 * 相同度（数组元素最大出现频次）的最短连续子数组长度
 * Input: nums = [1,2,2,3,1,4,2]
 * Output: 6
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> pos; // {start, end, cnt}
        int maxCount = 0, minLen = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (pos.find(nums[i]) != pos.end()) {
                pos[nums[i]][1] = i;
                pos[nums[i]][2]++;
            } else {
                pos[nums[i]] = {i, i, 1};
            }
            if (pos[nums[i]][2] > maxCount) {
                maxCount = pos[nums[i]][2];
                minLen = pos[nums[i]][1] - pos[nums[i]][0] + 1;
            } else if (pos[nums[i]][2] == maxCount) {
                minLen = min(minLen, pos[nums[i]][1] - pos[nums[i]][0] + 1);
            }
        }
        return minLen;
    }
};

int main()
{
    vector<int> nums = {1,2,2,3,1,4,2};
    Solution s;
	cout << s.findShortestSubArray(nums) << endl;

    return 0;
}
