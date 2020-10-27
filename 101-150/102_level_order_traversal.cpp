/*
 * @see https://leetcode.com/problems/binary-tree-level-order-traversal/
 * 
 * 层序遍历
 * Input: [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
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
	vector<vector<int>> levelOrder(TreeNode* root) {
	    if (!root) return {};
		vector<int> lev;
		vector<vector<int>> res;
		queue<TreeNode*> q;
		int parent = 1, child = 0;
		q.push(root);

		while (!q.empty()) {
			root = q.front();
			q.pop();
			parent--;
			lev.push_back(root->val);
			if (root->left) {
				q.push(root->left);
				child++;
			}
			if (root->right) {
				q.push(root->right);
				child++;
			}
			if (parent == 0) {
				parent = child;
				child = 0;
				res.push_back(lev);
				lev.clear();
			}
		}
		return res;
	}

	/*
	 * Optimize: queue.size() is the count of nodes in current level.
	 * 
	 * @see https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33450/Java-solution-with-a-queue-used
	 *
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
	    if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int cnt = q.size();
			vector<int> level(cnt);
			for (int i = 0; i < cnt; i++) {
				root = q.front();
				q.pop();
				level[i] = root->val;
				if (root->left) q.push(root->left);
				if (root->right) q.push(root->right);
			}
			res.push_back(level);
		}
		return res;
	}
	 */

	/*
	 * use dfs 
	 *
	 * @see https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33445/Java-Solution-using-DFS
	 *
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> res;
    	dfs(res, root, 0);
    	return res;
    }

    void dfs(vector<vector<int>> &res, TreeNode* root, int height) {
    	if (!root) return;
    	if (res.size() <= height) {
    		res.push_back({});
    	}
    	res[height].push_back(root->val);
    	dfs(res, root->left, height + 1);
    	dfs(res, root->right, height + 1);
    }
     */
};

int main()
{
	TreeNode a(3), b1(9), b2(20), c1(15), c2(7);

	a.left = &b1; a.right = &b2;
	b2.left = &c1; b2.right = &c2;

	Solution s;
	vector<vector<int>> res = s.levelOrder(&a);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
}
