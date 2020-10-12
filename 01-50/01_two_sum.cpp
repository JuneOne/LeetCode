/*
 * 返回 nums 数组中，和为 target 的元素的下标 
 * Input: nums = [2, 7, 11, 15], target = 9
 * Output: [0, 1]
 *
 * Note: 用 unordered_map 更快
 */
#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            int j = target - nums[i];
            if (index.find(j) == index.end()) {
                index[nums[i]] = i;
            } else {
                return vector<int>({index[j], i});
            }
        }
        return vector<int>();
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;
    Solution s;
    for (auto const &v : s.twoSum(nums, target)) {
        printf("%d ", v);
    }
}

