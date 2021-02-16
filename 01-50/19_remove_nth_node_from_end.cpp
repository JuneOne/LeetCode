/*
 * @see https://leetcode.com/problems/remove-nth-node-from-end-of-list
 *
 * 删掉链表的倒数第N个节点（一次遍历）
 * Input: head = [1,2,3,4,5], n = 5
 * Output: [2,3,4,5]
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head, *prev = NULL;
        while (n--) {
            fast = fast->next;
        }
        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev) {
            prev->next = slow->next;
        } else {
            head = slow->next;
        }
        delete slow;
        return head;
    }

    /*
     * add a dummy node: ListNode* dummy = new ListNode(0, head);
     *
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = head;
        while (n--) {
            fast = fast->next;
        }
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;

        head = dummy->next;
        delete dummy;
        return head;
    }
     */

    /*
     * use a "pointer to the entry pointer" without using any conditionals.
     * @see http://wordaligned.org/articles/two-star-programming
     *
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** pp = &head;
        ListNode* fast = head;
        while (n--) {
            fast = fast->next;
        }
        while (fast) {
            pp = &((*pp)->next);
            fast = fast->next;
        }
        ListNode* tmp = *pp;
        *pp = (*pp)->next;
        delete tmp;
        return head;
    }
     */
};

int main()
{
    vector<int> values = {1,2,3,4,5};
    vector<ListNode*> nodes;
    for (auto& val: values) {
        nodes.push_back(new ListNode(val));
    }
    for (int i = 1; i < nodes.size(); i++) {
        nodes[i-1]->next = nodes[i];
    }
    Solution s;
    ListNode* res = s.removeNthFromEnd(nodes[0], 5);
    while (res) {
        cout << res->val << ' ';
        res = res->next;
    }
    cout << endl;

    return 0;
}

