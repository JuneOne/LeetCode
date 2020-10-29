/*
 * @see https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * 
 * 根据升序链表构造BST，且各个节点子树节点数相差不超过1
 * Input: [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 *
 * Note: slow & fast pointer to find mid node.
 */
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {
        return help(head, NULL);
    }

    /*
     * @see https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/discuss/35476/Share-my-JAVA-solution-1ms-very-short-and-concise.
     */
    TreeNode* help(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return NULL;
        }
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = help(head, slow);
        root->right = help(slow->next, tail);

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
    ListNode a(-10), b(-3), c(0), d(5), e(9);
    a.next = &b; b.next = &c; c.next = &d; d.next = &e;

    Solution s;
    preOrderPrint(s.sortedListToBST(&a), 0);

    return 0;
}
