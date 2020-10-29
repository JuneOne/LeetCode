/*
 * @see https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * 
 * 根据前中序建树
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: 3
 *        / \
 *       9  20
 *          / \
 *         15  7
 *
 * Consider: how to get postorder traversal without building tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return help(0, 0, inorder.size() - 1, preorder, inorder);
    }

    /*
     * @see https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34538/My-Accepted-Java-Solution
     *
     * preorder[i] is root. Then find both left and right subtree's root index in preorder, and left & right range in inorder array.
     */
    TreeNode* help(int root, int start, int end, vector<int>& preorder, vector<int>& inorder) {
        if (root > preorder.size() || start > end) {
            return NULL;
        }
        TreeNode* tree = new TreeNode(preorder[root]);
        int index;
        // can use a map to avoid traversal every time
        for (int i = start; i <= end; i++) {
            if (inorder[i] == preorder[root]) {
                index = i;
                break;
            }
        }
        tree->left = help(root + 1, start, index - 1, preorder, inorder);
        tree->right = help(root + index - start + 1, index + 1, end, preorder, inorder);

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
