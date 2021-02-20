/*
 * @see https://leetcode.com/problems/find-the-duplicate-number
 * 
 * n + 1 长度数组，每个数取值范围 [1, n]，求唯一重复数
 * Input: nums = [1,1,2]
 * Output: 1
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> ele;
        for (auto& num: nums) {
            if (ele.find(num) != ele.end()) {
                return num;
            }
        }
        return 0;
    }

    /*
     * reduce the problem to Linked List Cycle II.
     * 注意 index = 0 不会是环出现的位置.
     *
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
     */
};

int main()
{
    vector<int> nums = {1,3,4,2,2};
    Solution s;
    cout << s.findDuplicate(nums) << endl;

    return 0;
}
