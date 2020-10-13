/*
 * @see https://leetcode.com/problems/add-two-numbers/
 * 
 * 两个用链表表示的数的和（数字逆序存放）
 * Input: l1 = [2, 4, 3], l2 = [5, 6, 4]
 * Output: [7, 0, 8]
 *
 * Note: top digit's carry
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode node;
        ListNode *p = &node;
        int carry = 0;
        while (l1 || l2 || carry) {
        	int num = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        	carry = num / 10;
        	p->next = new ListNode(num % 10);
      		p = p->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return node.next;
    }
};

int main() 
{
	ListNode a(2), b(4), c(3);
	ListNode d(5), e(6), f(4);

	a.next = &b; b.next = &c;
	d.next = &e; e.next = &f;

	Solution s;
	ListNode *p = s.addTwoNumbers(&a, &d);

	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
}
