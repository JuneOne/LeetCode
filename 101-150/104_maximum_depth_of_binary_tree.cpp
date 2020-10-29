/*
 * @see https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * 
 * 最大深度
 * Input: [3,9,20,null,null,15,7]
 * Output: 3
 */
#include <iostream>
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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    /*
     * bfs
     *
     * @see https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/34238/Clean-Java-Iterative-Solution
     *
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                root = q.front();
                q.pop();
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            depth++;
        }
        return depth;
    }
     */
     
};

int main()
{
	TreeNode a(3), b1(9), b2(20), c1(15), c2(7);

	a.left = &b1; a.right = &b2;
	b2.left = &c1; b2.right = &c2;

	Solution s;
	cout << s.maxDepth(&a);
}
