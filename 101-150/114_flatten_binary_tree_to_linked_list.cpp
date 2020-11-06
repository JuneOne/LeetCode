/*
 * @see https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 *
 * 将树就地展平为链表
 * Input: 1
 *       / \
 *      2   5
 *     / \   \
 *    3   4   6
 *
 * Output: 1
 *          \
 *           2
 *            \
 *            ...
 *              \
 *               6
 *
 * Note: pointer should be initialized as null explicitly.
 */
#include <stdio.h>

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
    void flatten(TreeNode* root) {
        TreeNode* tail = NULL;
        help(root, tail);
    }

    void help(TreeNode* root, TreeNode* &tail) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            tail = root;
            return;
        }
        TreeNode *right = root->right;
        TreeNode *left_tail = NULL, *right_tail;
        if (root->left) {
            help(root->left, left_tail);
            root->right = root->left;
            root->left = NULL;
            tail = left_tail;
        }
        if (right) {
            help(right, right_tail);
            if (left_tail) {
                left_tail->right = right;
            }
            tail = right_tail;
        }
    }
};

int main()
{
    TreeNode a(1), b1(2), b2(5), c1(3), c2(4), c3(6);

    a.left = &b1; a.right = &b2;
    b1.left = &c1; b1.right = &c2; b2.left = &c3;

    TreeNode *p = &a;
    Solution s;
    s.flatten(p);
    while (p) {
        printf("%d ", p->val);
        p = p->right;
    }

    return 0;
}
