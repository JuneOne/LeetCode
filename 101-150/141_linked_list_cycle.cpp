/*
 * @see https://leetcode.com/problems/linked-list-cycle
 * 
 * 判断链表是否有环
 * Input: head = [3,2,0,-4], pos = 1（仅用来辅助标记环的位置）
 * Output: true
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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    ListNode a(3), b(2), c(0), d(-4);
    a.next = &b; b.next = &c; c.next = &d;
    d.next = &b; // pos = 1
    Solution s;
    cout << s.hasCycle(&a) << endl;

    return 0;
}
