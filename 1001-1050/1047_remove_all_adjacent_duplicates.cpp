/*
 * @see https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string
 * 
 * 反复删除字符串的相邻重复项
 * Input: S = "abbaca"
 * Output: "ca"
 *
 * Note: 字符串支持“栈”操作
 */
#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        string str = "";
        for (char& ch: S) {
            if (!str.empty() && str.back() == ch) {
                str.pop_back();
            } else {
                str.push_back(ch);
            }
        }
        return str;
    }
};

int main()
{
    Solution s;
	cout << s.removeDuplicates("abbaca") << endl;

    return 0;
}
