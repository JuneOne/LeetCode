/*
 * @see https://leetcode.com/problems/spiral-matrix-ii
 * 
 * 螺旋矩阵II.
 * Input: n = 3
 * Output: [[1,2,3],[8,9,4],[7,6,5]]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> visit(n, vector<int>(n, 0)); // 因为放的是正整数，所以非0就是访问过了
        int num = n * n;
        int i = 0, j = 0;
        int flag = 0;
        for (int cnt = 1; cnt <= num; cnt++) {
            visit[i][j] = cnt;
            int newI = i + direction[flag][0];
            int newJ = j + direction[flag][1];
            if (newI < 0 || newI >= n || newJ < 0 || newJ >= n || visit[newI][newJ] > 0) {
                flag = (flag + 1) % 4;
            }
            i += direction[flag][0];
            j += direction[flag][1];
        }
        return visit;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res = s.generateMatrix(3);
    for (auto const& row: res) {
        for (const int& val: row) {
            cout << val << ' ';
        }
        cout << endl;
    }

    return 0;
}
