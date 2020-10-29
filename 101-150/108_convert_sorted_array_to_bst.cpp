/*
 * @see https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * 
 * 根据升序数组构造BST，且各个节点子树节点数相差不超过1
 * Input: [-10,-3,0,5,9]
 * Possible Output: [0,-3,9,-10,null,5]
 */
#include <stdio.h>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(0, nums.size() - 1, nums);
    }

    TreeNode* help(int s, int e, vector<int>& nums) {
        if (s > e) {
            return NULL;
        }
        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = help(s, mid - 1, nums);
        root->right = help(mid + 1, e, nums);

        return root;
    }
};

void preOrderPrint(TreeNode* root, int height)
{
    for (int i = 0; i < height; i++) {
        printf("-----");
    }
    if (!root) {
        printf("null\n");
        return;
    }
    printf("[%d]\n", root->val);
    preOrderPrint(root->left, height + 1);
    preOrderPrint(root->right, height + 1);
}

int main()
{
    vector<int> nums = {-10,-3,0,5,9};
    Solution s;
    preOrderPrint(s.sortedArrayToBST(nums), 0);

    return 0;
}
