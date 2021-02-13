/*
 * @see https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * 
 * a[i] ∈ [1, n](n = array size), 且出现 1~2 次，输出出现两次的数字
 * Input: [4,3,2,7,8,2,3,1]
 * Output: [2,3]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (auto num : nums) {
            int index = abs(num) - 1;
            if (nums[index] < 0) {
                res.push_back(index + 1);
            }
            nums[index] = -nums[index];
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution s;
    vector<int> res = s.findDuplicates(nums);
    for (auto& v : res) {
        cout << v << ' ';
    }
    cout << endl;
}
