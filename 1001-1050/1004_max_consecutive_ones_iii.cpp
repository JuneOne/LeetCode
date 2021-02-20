/*
 * @see https://leetcode.com/problems/max-consecutive-ones-iii
 * 
 * 最大连续1的个数（最多可以将K个值翻成1）
 * Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
 * Output: 6
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int one = 0, left = 0, maxLen = 0;
        for (int right = 0; right < A.size(); right++) {
            if (A[right] == 1) one++;
            while (right - left + 1 - one > K) {
                if (A[left] == 1) one--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main()
{
    vector<int> A = {1,0,0,0,1,1,1};
    Solution s;
	cout << s.longestOnes(A, 2) << endl;

    return 0;
}
