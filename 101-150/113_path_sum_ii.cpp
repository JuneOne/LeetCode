/*
 * @see https://leetcode.com/problems/path-sum-ii/
 *
 * 根到叶节点的节点和 = sum 的所有路径
 * Input: [5,4,8,11,null,13,4,7,2,null,null,null,1], sum = 22
 * Output: [[5,4,11,2], [5,8,4,5]]
 */
#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> res;
        help(root, sum, path, res);
        return res;
    }

    void help(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &res) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) {
            res.push_back(path);
        }
        help(root->left, sum - root->val, path, res);
        help(root->right, sum - root->val, path, res);
        path.pop_back();
    }
};

int main()
{
    TreeNode a(5), b1(4), b2(8), c1(11), c2(13), c3(4), d1(7), d2(2), d3(5), d4(1);

    a.left = &b1; a.right = &b2;
    b1.left = &c1; b2.left = &c2; b2.right = &c3;
    c1.left = &d1; c1.right = &d2; c3.left = &d3; c3.right = &d4;

    Solution s;
    vector<vector<int>> res = s.pathSum(&a, 22);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}
