/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(-1);
        auto cmp = [] (ListNode *a, ListNode *b) { return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(ListNode *node: lists) {
            if(node) {
                pq.push(node);
            }
        }
        ListNode *curr, *prev;
        prev = dummy;
        while(!pq.empty()) {
            curr = pq.top();
            pq.pop();
            prev->next = curr;
            prev = prev->next;

            curr = curr->next;
            if(curr) {
                pq.push(curr);
            }
        }
        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};
