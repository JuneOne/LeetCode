/*
 * @see https://leetcode.com/problems/dungeon-game/
 * 
 * 从左上到右下（每次往下/往右走），且走到每一格血量都要大于0，初始血量至少是多少.
 * Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
 * -2(K) -3   3
 * -5    -10  1
 * 10    30  -5(P)
 * Output: 7(-2-> -3-> 3-> 1-> -5)
 *
 * Note:
 * 1. 从左上->右下: 最多能获得多少血量
 * 2. 从右下->左上: 初始血量至少是多少，能在行走的过程中至少保持生命值为1
 * 3. 可以先推演一维数组的情况
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0) {
            return 0;
        }
        int row = dungeon.size();
        int column = dungeon[0].size();
        dungeon[row-1][column-1] = max(1, 1 - dungeon[row-1][column-1]);

        for (int i = row - 2; i >= 0; i--) {
            dungeon[i][column-1] = max(1, dungeon[i+1][column-1] - dungeon[i][column-1]);
        }
        for (int j = column - 2; j >= 0; j--) {
            dungeon[row-1][j] = max(1, dungeon[row-1][j+1] - dungeon[row-1][j]);
        }

        for (int i = row - 2; i >= 0; i--) {
            for (int j = column - 2; j >= 0; j--) {
                int min_hp = min(dungeon[i+1][j], dungeon[i][j+1]);
                dungeon[i][j] = max(1, min_hp - dungeon[i][j]);
            }
        }
        return dungeon[0][0];
    }
};

int main()
{
    vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    Solution s;
    cout << s.calculateMinimumHP(dungeon) << endl;
}
