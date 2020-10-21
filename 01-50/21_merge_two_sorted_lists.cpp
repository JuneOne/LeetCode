/*
 * @see https://leetcode.com/problems/merge-two-sorted-lists/
 * 
 * 合并两个有序数组
 * Input: l1 = [1,2,4], l2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 */
#include <cstdio>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode;
        ListNode *p = head;
        while (l1 || l2) {
        	if (!l1) {
        		p->next = l2;
        		l2 = l2->next;
        	} else if (!l2 || l1->val < l2->val) {
        		p->next = l1;
        		l1 = l1->next;
        	} else {
        		p->next = l2;
        		l2 = l2->next;
        	}
        	p = p->next;
        }
        p = head->next;
        delete head;
        return p;
    }

    /*
     * @see https://leetcode.com/problems/merge-two-sorted-lists/discuss/9715/Java-1-ms-4-lines-codes-using-recursion
     *
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res;
        if (!l1) {
			return l2;
        }
        if (!l2) {
			return l1;
        }
        if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
        } else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
        }
    }
     */
    
};

int main()
{
	ListNode a(1), b(2), c(4);
	ListNode d(1), e(3), f(4);
	a.next = &b;
	b.next = &c;
	d.next = &e;
	e.next = &f;
	Solution s;
	ListNode *head = s.mergeTwoLists(&a, &d);
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
}
