/*
 * @see https://leetcode.com/problems/climbing-stairs/
 * 
 * 爬楼梯：每次爬 1/2 步，有几种方式爬到 N 层
 * Input: n = 3
 * Output: 3
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) { 
        vector<int> dp(n + 3, 0);
        dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    };
};

int main()
{
    Solution s;
    cout << s.climbStairs(3) << endl;
}
