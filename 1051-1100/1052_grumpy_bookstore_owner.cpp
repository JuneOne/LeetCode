/*
 * @see https://leetcode.com/problems/grumpy-bookstore-owner
 * 
 * 最多满意顾客数
 * Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
 * Output: 16（书店老板在最后 3 分钟保持冷静）
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    	int l = 0, r = 0;
    	int actual = 0, extra = 0, maxExtra = 0;
    	for (; r < customers.size(); r++) {
    		actual += (1 - grumpy[r]) * customers[r];
    		extra += grumpy[r] * customers[r];
    		maxExtra = max(extra, maxExtra);
			if (r - l + 1 == X) {
				extra -= grumpy[l] * customers[l];
				l++;
			}
    	}
    	return actual + maxExtra;
    }
};

int main()
{
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    Solution s;
	cout << s.maxSatisfied(customers, grumpy, 3) << endl;

    return 0;
}
