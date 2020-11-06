/*
 * @see https://leetcode.com/problems/balanced-binary-tree/
 * 
 * 平衡树：判断各个节点子树节点数相差不超过1
 * Input: [3,9,20,null,null,15,7]
 * Output: true
 */
#include <iostream>
#include <cmath>

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
    bool isBalanced(TreeNode* root) {
        int height;
        return help(root, height);
    }

    bool help(TreeNode* root, int &height) {
        int left_height, right_height;
        if (!root) {
            height = 0;
            return true;
        }
        if (!help(root->left, left_height) || !help(root->right, right_height) || abs(left_height - right_height) > 1) {
            return false;
        }
        height = max(left_height, right_height) + 1;
        return true;
    }
};

int main()
{
    TreeNode a(3), b1(9), b2(20), c1(15), c2(7);

    a.left = &b1; a.right = &b2;
    b2.left = &c1; b2.right = &c2;

    Solution s;
    cout << s.isBalanced(&a);
}
