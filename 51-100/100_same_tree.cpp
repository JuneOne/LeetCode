/*
 * @see https://leetcode.com/problems/same-tree/
 * 
 * 判断两个二叉树是否相同
 * Input: [1,2,3], [1,2,3]
 * Output: true
 */
#include <iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if (p && q) {
    		return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		return !p && !q;
    }
};

int main()
{
	TreeNode a(1), b(2), c(3);
	TreeNode d(1), e(2), f(3);

	a.left = &b; a.right = &c;
	d.left = &e; d.right = &f;

	Solution s;
	cout << s.isSameTree(&a, &d);
}
