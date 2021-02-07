/*
 * @see https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 * 
 * 每次从开头/末尾拿牌，求拿满 K 张的最大点数.
 * Input: cardPoints = [1,2,3,4,5,6,1], k = 3
 * Output: 12（拿右边的3张）
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * 也可以求 n - k 窗口的最小值，然后用 totalScore 减掉.
     */
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int score = 0;
        for (int i = n - k; i < n; i++) {
            score += cardPoints[i];
        }
        int maxScore = score;
        for (int i = 0; i < k; i++) {
            score += (cardPoints[i] - cardPoints[n-k+i]);
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};

int main()
{
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    Solution s;
	cout << s.maxScore(cardPoints, 3) << endl;
}
