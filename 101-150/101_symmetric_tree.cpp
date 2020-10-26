/*
 * @see https://leetcode.com/problems/symmetric-tree/
 * 
 * 判断对称树
 * Input: [1,2,2,3,4,4,3]
 * Output: true
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
	bool isSymmetric(TreeNode* root) {
		return !root || dfs(root->left, root->right);
	}
	bool dfs(TreeNode* left, TreeNode* right) {
		if (left && right) {
			return (left->val == right->val) && dfs(left->left, right->right) && dfs(left->right, right->left);
		}
		return !left && !right;
	}

	/*
	 * bfs
	 *
	bool isSymmetric(TreeNode* root) {
		if (!root) {
			return true;
		}
		queue<TreeNode*> q;

		q.push(root->left);
		q.push(root->right);
		while (!q.empty()) {
			TreeNode* left = q.front(); q.pop();
			TreeNode* right = q.front(); q.pop();
			if (!left && !right) {
				continue;
			}
			if (!left || !right || left->val != right->val) {
				return false;
			}
			q.push(left->left);
			q.push(right->right);
			q.push(left->right);
			q.push(right->left);
		}
		return true;
    }
     */
};

int main()
{
	TreeNode a(1), b1(2), b2(2), c1(3), c2(4), c3(4), c4(3);

	a.left = &b1; a.right = &b2;
	b1.left = &c1; b1.right = &c2; b2.left = &c3; b2.right = &c4;

	Solution s;
	cout << s.isSymmetric(&a);
}
