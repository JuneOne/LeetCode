/*
 * @see https://leetcode.com/problems/generate-parentheses/
 * 
 * 生成正确的括号对
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]

 * Note: can't use s.append(1, '(') to replace s + '('
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, n, "", res);
        return res;
    }

    void generate(int left, int right, string s, vector<string> &res) {
    	if (left == 0 && right == 0) {
    		res.push_back(s);
    		return;
    	}
    	if (left > 0) {
    		generate(left - 1, right, s + '(', res);
    	}
    	if (left < right) {
    		generate(left, right - 1, s + ')', res);
    	}
    }
};

int main()
{
	Solution s;
	vector<string> res = s.generateParenthesis(3);
	for (auto const &val : res) {
		cout << val << endl;
	}
}
