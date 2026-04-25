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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = head;
        while (n > 0) {
            fast = fast->next;
            n--;
        }
        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *prev = slow;
        ListNode *delNode = prev->next;
        prev->next = delNode->next;
        return dummy->next;
    }
};
