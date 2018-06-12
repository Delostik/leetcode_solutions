/*
    题意：合并多个有序链表
    解法：用个堆
*/

#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                heap.push(make_pair(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }
        ListNode *res = NULL, *p;
        while (!heap.empty()) {
            auto top = heap.top();
            heap.pop();
            if (!res) {
                p = res = new ListNode(top.first);
            } else {
                p->next = new ListNode(top.first);
                p = p->next;
            }
            if (lists[top.second]) {
                heap.push(make_pair(lists[top.second]->val, top.second));
                lists[top.second] = lists[top.second]->next;
            }
        }
        return res;
    }
};
