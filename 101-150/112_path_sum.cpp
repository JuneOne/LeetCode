/*
 * @see https://leetcode.com/problems/path-sum/
 * 
 * 是否存在从根到叶节点的节点值之和 = sum
 * Input: [5,4,8,11,null,13,4,7,2,null,null,null,1], sum = 22
 * Output: true (5->4->11->2)
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
    bool hasPathSum(TreeNode* root, int sum) {
    	if (!root) return false;
    	if (!root->left && !root->right && root->val == sum) 
    		return true;
    	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};


int main()
{
    TreeNode a(5), b1(4), b2(8), c1(11), c2(13), c3(4), d1(7), d2(2), d3(1);

    a.left = &b1; a.right = &b2;
    b1.left = &c1; b2.left = &c2; b2.right = &c3;
    c1.left = &d1; c1.right = &d2; c3.right = &d3;

    Solution s;
    cout << s.hasPathSum(&a, 22);
}
