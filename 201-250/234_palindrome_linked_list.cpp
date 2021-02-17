/*
 * @see https://leetcode.com/problems/palindrome-linked-list
 * 
 * 判断回文链表
 * Input: 1->2->2->1
 * Output: true
 */
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        stack<int> S;
        while (fast && fast->next) {
            S.push(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) { // 链表节点数为奇数
            slow = slow->next;
        }
        while (slow) {
            if (slow->val != S.top()) {
                return false;
            }
            S.pop();
            slow = slow->next;
        }
        return true;
    }

    /*
     * O(1) space: reverse the first half while finding the middle, (and reverse the first half back while comparing)
     *
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        ListNode *prev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            head = slow->next;
            slow->next = prev;
            prev = slow;
            slow = head;
        } // 注意此时 head 和 prev 之间是没有连接的
        if (fast) { // 链表节点数为奇数
            slow = slow->next;
        }
        // 需要把链表翻转回去，故用标记记录是否是回文
        // 此时 prev 是链表头，head 相当于 ”prev“
        bool flag = true;
        while (prev) {
            if (flag && prev->val != slow->val) {
                flag = false;
            }
            ListNode *next = prev->next;
            prev->next = head;
            head = prev;
            prev = next;
            slow = slow->next;
        }
        return flag;
    }
     */
};

int main()
{
    ListNode a(1), b(2), c(2), d(1);
    a.next = &b; b.next = &c; c.next = &d; 
    Solution s;
    ListNode* head = &a;
    cout << s.isPalindrome(head) << endl;
    // 是否有修改原链表
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;

    return 0;
}
