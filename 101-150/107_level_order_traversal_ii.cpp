/*
 * @see https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 * 
 * 自顶向上层序遍历
 * Input: [3,9,20,null,null,15,7]
 * Output: [[15,7],[9,20],[3]]
 *
 * Note: o(n) time reverse with space o(1).
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
        	return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
        	int size = q.size();
        	vector<int> level(size);
        	for (int i = 0; i < size; i++) {
        		root = q.front();
        		q.pop();
        		level[i] = root->val;
        		if (root->left) q.push(root->left);
        		if (root->right) q.push(root->right);
        	}
        	res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
	TreeNode a(3), b1(9), b2(20), c1(15), c2(7);

	a.left = &b1; a.right = &b2;
	b2.left = &c1; b2.right = &c2;

	Solution s;
	vector<vector<int>> res = s.levelOrderBottom(&a);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
}
