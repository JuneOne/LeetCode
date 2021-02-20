/*
 * @see https://leetcode.com/problems/move-zeroes
 * 
 * 将所有的 0 移到尾端（in-place）
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;
        for (auto& num: nums) {
            if (num != 0) {
                nums[insertPos++] = num;
            }
        }
        while (insertPos < nums.size()) {
            nums[insertPos++] = 0;
        }
    }

    /*
     * snowball solution.
     * @see https://leetcode.com/problems/move-zeroes/discuss/172432/THE-EASIEST-but-UNUSUAL-snowball-JAVA-solution-BEATS-100-(O(n))-%2B-clear-explanation
     *
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero++;
            } else {
                swap(nums[i], nums[i-zero]);
            }
        }
    }
     */

    /*
     * two pointers: 左指针左边均为非零数，左指针~右指针均为零.
     *
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right]) {
                swap(nums[left++], nums[right]);
            }
            right++;
        }
    }
     */
};

int main()
{
    vector<int> nums = {0,1,0,3,12};
    Solution s;
    s.moveZeroes(nums);
    for (auto& num: nums) {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}
