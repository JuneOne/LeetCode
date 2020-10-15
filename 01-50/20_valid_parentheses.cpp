/*
 * @see https://leetcode.com/problems/valid-parentheses/
 * 
 * 正确的括号对
 * Input: s = "{[]}"
 * Output: true
 *
 * Note: stack; beautiful code
 */
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
    	stack<char> ch;
        for (auto const &c : s) {
        	if (c == '(' || c == '{' || c == '[') {
        		ch.push(c);
        	} else if (ch.empty() || 
        		(c == ')' && ch.top() != '(' ) ||
        		(c == '}' && ch.top() != '{' ) ||
        		(c == ']' && ch.top() != '[' )
        	) {
        		return false;
        	} else {
        		ch.pop();        		
        	}
        }
        return ch.empty();
    }
    /*
     * @see https://leetcode.com/problems/valid-parentheses/discuss/9178/Short-java-solution
     *
    bool isValid(string s) {
    	stack<char> ch;
        for (auto const &c : s) {
        	if (c == '(') {
				ch.push(')');
        	} else if (c == '{') {
				ch.push('}');
        	} else if (c == '[') {
				ch.push(']');
        	} else if (ch.empty() || ch.top() != c) {
				return false;
        	} else {
				ch.pop();
        	}
        }
        return ch.empty();
    }
     */
};

int main()
{
	Solution s;
	printf("%d", s.isValid("]"));
}
