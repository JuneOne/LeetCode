/*
 * @see https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * 
 * 从根到叶节点的最小节点数（只有一个节点，则为叶节点）
 * Input: [3,9,20,null,null,15,7]
 * Output: 2
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
    int minDepth(TreeNode* root) {
    	if (!root) {
    		return 0;
    	}
    	int left = minDepth(root->left);
    	int right = minDepth(root->right);
    	return ((left == 0 || right == 0 ) ? left + right : min(left, right)) + 1;
    }

    /*
     * Better one.
     *
    int minDepth(TreeNode* root){
        if(!root)
            return 0;
        if(!root->left)
            return 1 + minDepth(root->right);
        if(!root->right)
            return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->right), minDepth(root->left));
    }
     */
};


int main()
{
    TreeNode a(3), b1(9), b2(20), c1(15), c2(7);

    a.left = &b1; a.right = &b2;
    b2.left = &c1; b2.right = &c2;
    // a.right = &b1; b1.right = &b2; b2.right = &c1; c1.right = &c2;

    Solution s;
    cout << s.minDepth(&a);
}
