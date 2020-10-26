/*
 * @see https://leetcode.com/problems/validate-binary-search-tree/
 * 
 * 判断二叉搜索树
 * Input: [2,1,3]
 * Output: true
 *
 * Note: dfs; top-down / bottom-up; consider leaf node.
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>

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
    /*
     * use tuple, but ugly.
     *
    bool isValidBST(TreeNode* root) {
        return !root ? true : get<0>(dfs(root));
    }

    tuple<bool, int, int> dfs(TreeNode *root) {
        if (!root->left && !root->right) {
            return {true, root->val, root->val};
        }

        if (!root->right) {
            tuple<bool, int, int> left_tuple = dfs(root->left);
            if (!get<0>(left_tuple)) {
                return left_tuple;
            }
            if (get<2>(left_tuple) < root->val) {
                return {true, get<1>(left_tuple), root->val};
            } else {
                return {false, INT_MAX, INT_MIN};
            }
        }

        if (!root->left) {
            tuple<bool, int, int> right_tuple = dfs(root->right);
            if (!get<0>(right_tuple)) {
                return right_tuple;
            }
            if (get<1>(right_tuple) > root->val) {
                return {true, root->val, get<2>(right_tuple)};
            } else {
                return {false, INT_MAX, INT_MIN};
            }
        }

        tuple<bool, int, int> left_tuple = dfs(root->left);
        if (!get<0>(left_tuple)) {
            return left_tuple;
        }
        tuple<bool, int, int> right_tuple = dfs(root->right);
        if (!get<0>(right_tuple)) {
            return right_tuple;
        }

        if (root->val > get<2>(left_tuple) && root->val < get<1>(right_tuple)) {
            return {true, get<1>(left_tuple), get<2>(right_tuple)};
        } else {
            return {false, INT_MAX, INT_MIN};
        }
    }
     */

    /*
     * use reference. By Jiang.
     *
    bool isValidBST(TreeNode* root) {
        int min, max;
        return dfs(root, min, max);
    }

    bool dfs(TreeNode *root, int &min, int &max) {
        int min_left, max_left, min_right, max_right;
        if (!root) {
            return true;
        }

        if (!root->left && !root->right) {
            min = max = root->val;
            return true;
        }

        if (!root->left) {
            if (!dfs(root->right, min_right, max_right) || min_right <= root->val) {
                return false;
            }
            min = root->val;
            max = max_right;
            return true;
        } 

        if (!root->right) {
            if (!dfs(root->left, min_left, max_left) || max_left >= root->val) {
                return false;
            }
            min = min_left;
            max = root->val;
            return true;
        }

        if (!dfs(root->right, min_right, max_right) || min_right <= root->val ||
            !dfs(root->left, min_left, max_left) || max_left >= root->val) {
            return false;
        }
        min = min_left;
        max = max_right;
        return true;
    }
     */

    /*
     * @see https://leetcode.com/problems/validate-binary-search-tree/discuss/32109/My-simple-Java-solution-in-3-lines
     *
     * use long, otherwise the solution will fail to pass the test case with INT_MIN / INT_MAX.
     *
     */
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* root, long min, long max) {
        if (!root) return true;
        if (root->val >= max || root->val <= min) return false;
        return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }

    /*
     * @see https://leetcode.com/problems/validate-binary-search-tree/discuss/32112/Learn-one-iterative-inorder-traversal-apply-it-to-multiple-tree-questions-(Java-Solution)
     * 
     * @see https://leetcode.com/problems/validate-binary-search-tree/discuss/32141/C%2B%2B-simple-recursive-solution
     */
};

int main()
{
    TreeNode a(INT_MAX), b(INT_MIN);
    a.left = &b;
    Solution s;
    cout << s.isValidBST(&a) << endl;
}
