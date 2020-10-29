/*
 * @see https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * 
 * 根据中后序建树
 * Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * Output: 3
 *        / \
 *       9  20
 *          / \
 *         15  7
 */
#include <iostream>
#include <stack>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return help(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
    
    TreeNode* help(int root, int start, int end, vector<int>& inorder, vector<int>& postorder) {
        if (root < 0 || start > end) {
            return NULL;
        }
        TreeNode* tree = new TreeNode(postorder[root]);
        int index;
        for (int i = start; i <= end; i++) {
            if (inorder[i] == postorder[root]) {
                index = i;
                break;
            }
        }
        tree->left = help(root - (end - index) - 1, start, index - 1, inorder, postorder);
        tree->right = help(root - 1, index + 1, end, inorder, postorder);

        return tree;
    }
};

int main()
{
	vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

	Solution s;
	cout << s.buildTree(preorder, inorder);
}
