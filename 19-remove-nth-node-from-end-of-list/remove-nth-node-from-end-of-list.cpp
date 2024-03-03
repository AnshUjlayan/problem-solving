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
        ListNode* newHead = new ListNode(0, head);
        ListNode* temp = newHead;
        int len = 0;
        while(temp) {
            temp = temp->next;
            len++;
        }
        temp = newHead;
        len -= n;
        while(--len > 0) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return newHead->next;
    }
};