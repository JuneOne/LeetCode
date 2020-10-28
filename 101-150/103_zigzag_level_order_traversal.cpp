/*
 * @see https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * 
 * 层序遍历
 * Input: [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;

        while(!q.empty()) {
        	int cnt = q.size();
        	vector<int> level(cnt);
        	for (int i = 0; i < cnt; i++) {
        		root = q.front();
        		q.pop();

        		int index = flag ? i : cnt - i - 1;
        		level[index] = root->val;

        		if (root->left) q.push(root->left);
        		if (root->right) q.push(root->right);
        	}
        	flag = !flag;
        	res.push_back(level);
        }
        return res;
    }

    /*
     * dfs
     *
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		dfs(res, root, 0);
		return res;
    }

    void dfs(vector<vector<int>> &res, TreeNode* root, int height) {
    	if (!root) return;
    	if (height >= res.size()) {
    		res.push_back({});
    	}
    	if (height % 2 == 0) {
    		res[height].push_back(root->val);
    	} else {
    		res[height].insert(res[height].begin(), root->val);
    	}
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
	vector<vector<int>> res = s.zigzagLevelOrder(&a);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
}
