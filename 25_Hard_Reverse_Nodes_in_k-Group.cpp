#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *res = new ListNode(-1);
        ListNode *curGroup, *p = head, *resp = res;

        while (p) {
            int cnt = 0;
            while (p && cnt < k) {
                cnt += 1;
                p = p->next;
            }
            if (cnt != k) {     
                resp->next = head;
                break;
            }
            resp->next = reverseNextK(head, k);
            while (resp->next) {
                resp = resp->next;
            }
            head = p;
        }
        return res->next;       
    }

private:
    ListNode* reverseNextK(ListNode* head, int k) {
        ListNode *originHead = head, *next = head->next;
        for (int i = 1; i < k; i++) {
            ListNode *tempNext = next->next;
            next->next = head;
            head = next;
            next = tempNext;
        }
        originHead->next = NULL;
        return head;
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);
    auto res = solution->reverseKGroup(list, 3);
    while (res) {
        cout << res->val << endl;
        res = res->next;
    }
}