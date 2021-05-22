/*
 * @see https://leetcode.com/problems/n-queens
 * 
 * Input: n = 4（1 <= n <= 9)
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> index;
    vector<vector<string>> results;

    vector<vector<string>> solveNQueens(int n) {
        help(0, n);
        return results;
    }

    // 记录每一行皇后放置的 index 就可以.
    // line = index.size(); 即当前要插入的行号.
    void help(int line, int n) {
        if (line == n) {
            vector<string> res;
            for (int i = 0; i < n; i++) {
                string s(n, '.');
                s[index[i]] = 'Q';
                res.push_back(s);
            }
            results.push_back(res);
        }
        // 当前行的 n 个位置都要尝试放.
        for (int i = 0; i < n; i++) {
            bool valid = true;
            for (int j = 0; j < index.size(); j++) {
                // cout << line << ' ' << i << ' ' << j << ' ' << index[j] << ' ' << endl;
                if (i == index[j] || (line - j) == abs(i - index[j])) {
                    // 注意不能在这里直接 return.
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;
            // cout << "line=" << line << ", push(" << i << ")" << endl;
            index.push_back(i);
            help(line + 1, n);
            // cout << "line=" << line << ", pop()" << endl;
            index.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<vector<string>> res = s.solveNQueens(4);
    for (auto &vec : res) {
        for (auto &str : vec) {
            cout << str << ' ';
        }
        cout << endl;
    }

    return 0;
}
