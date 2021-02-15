/*
 * @see https://leetcode.com/problems/container-with-most-water
 *
 * 两条纵轴 + X轴围成的最大面积
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49  (8-1)*min(height(1),height(8))
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @see https://leetcode.com/problems/container-with-most-water/discuss/6099/Yet-another-way-to-see-what-happens-in-the-O(n)-algorithm
     * the only thing you need to show is that you don't make a mistake when you reduce the problem.
     */
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            water = max(water, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return water;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution s;
    cout << s.maxArea(height) << endl;

    return 0;
}

