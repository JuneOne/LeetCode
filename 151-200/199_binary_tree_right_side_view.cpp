/*
 * @see https://leetcode.com/problems/binary-tree-right-side-view/
 *
 * 每层最右的节点值
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 */
#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int num, size = q.size();
            for (int i = 0; i < size; i++) {
                root = q.front();
                q.pop();
                num = root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            res.push_back(num);
        }
        return res;
    }
};

int main()
{
    TreeNode a(1);
    TreeNode b(2), c(3);
    TreeNode d(5), e(4);

    a.left = &b; a.right = &c;
    b.right = &d; c.right = &e;

    Solution s;
    vector<int> res = s.rightSideView(&a);
    for (auto const &val : res) {
        cout << val << ' ';
    }
}
