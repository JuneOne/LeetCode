/*
 * @see https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
 * 
 * LCA算法.
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 *         3
 *       /   \
 *      5(p)  1
 *     / \   / \
 *    6   2 0   8
 *       / \
 *      7   4(q)
 * Output: 5
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path, path_p, path_q;
        getPath(root, p, path, path_p, false);
        getPath(root, q, path, path_q, false);

        TreeNode* common;
        int len = min(path_p.size(), path_q.size());
        for (int i = 0; i < len; i++) {
        	if (path_p[i] != path_q[i]) {
        		break;
        	}
        	common = path_p[i];
        }
        return common;
    }

    void getPath(TreeNode* root, TreeNode* node, vector<TreeNode*> &path, vector<TreeNode*> &result, bool search) {
    	if (!root || search) {
    		return;
    	}
    	path.push_back(root);
    	if (root == node) {
    		result = path;
    		search = true;
    	}
    	getPath(root->left, node, path, result, search);
    	getPath(root->right, node, path, result, search);
    	path.pop_back();
    }
};

int main() 
{
	TreeNode a(1), b(2);
	a.left = &b;
	Solution s;
	TreeNode* common = s.lowestCommonAncestor(&a, &a, &b);
	cout << common->val;

	return 0;
}
