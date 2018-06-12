/*
    题意：两个链表表示的正数求和
    解法：挨着处理进位就行了
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(l1->val + l2->val);
        ListNode *p = res;
        l1 = l1->next, l2 = l2->next;
        int carry = p->val / 10;
        p->val %= 10;
        for (; l1 && l2; l1 = l1->next, l2 = l2->next) {
            p->next = new ListNode(l1->val + l2->val + carry);
            p = p->next;
            carry = p->val / 10;
            p->val %= 10;
        }
        if (l1 || l2) {
            auto iter = l1;
            if (l2) iter = l2;
            for (; iter; iter = iter->next) {
                p->next = new ListNode(iter->val + carry);
                p = p->next;
                carry = p->val / 10;
                p->val %= 10;
            }
        }
        if (carry) {
            p->next = new ListNode(carry);
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *l1, *l2;
    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    auto res = solution->addTwoNumbers(l1, l2);
    for (; res; res = res->next) {
        cout << res->val << endl;
    }

}