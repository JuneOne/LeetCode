/*
 * @see https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * 
 * a[i] ∈ [1, n](n = array size), 输出 [1,n] 中不在数组里出现过的数
 * Input: [4,3,2,7,8,2,3,1]
 * Output: [5,6]
 */
#include <iostream>
#include <vector>
// #include <unordered_map>

using namespace std;

class Solution {
public:
    /*
     * 相当于把 count 数组压缩为 + / -
     */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            nums[index] = -abs(nums[index]);
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }

    /*
     * intuitive solution, O(N) space.
     *
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> numMap;
        for (auto& num : nums) {
            numMap[num]++;
        }
        vector<int> res;
        for (int i = 1; i <= nums.size(); i++) {
            if (!numMap[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
     */

    /*
     * slower one.
     *
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto& num : nums) {
            int index = (num - 1) % n; // !Tip: 0 ≤ num - 1 ≤ n - 1
            nums[index] = nums[index] + n;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                res.push_back(i + 1);
            }
            cout << nums[i] << endl;
        }
        return res;
    }
     */
};

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution s;
    vector<int> res = s.findDisappearedNumbers(nums);
    for (auto& v : res) {
        cout << v << ' ';
    }
    cout << endl;
}
