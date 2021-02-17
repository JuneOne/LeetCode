/*
 * @see https://leetcode.com/problems/linked-list-cycle-ii
 * 
 * 返回链表中环的开始节点
 * Input: head = [3,2,0,-4], pos = 1（仅用来辅助标记环的位置）
 * Output: 2nd node
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                while (head != fast) {
                    head = head->next;
                    fast = fast->next;
                }
                return head;
            }
        }
        return NULL;
    }
};

int main()
{
    ListNode a(3), b(2), c(0), d(-4);
    a.next = &b; b.next = &c; c.next = &d;
    d.next = &b; // pos = 1
    Solution s;
    ListNode* start = s.detectCycle(&a);
    if (start) {
        cout << start->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    return 0;
}
