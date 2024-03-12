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
//       [-----|----]
// 0 1 4 6 3 1 6 11 6 7
//   [-------]
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *newHead = new ListNode(0, head);
        map<int,ListNode*> mp;
        int sum = 0;
        newHead->next = head;
        head = newHead;
        while(head) {
            sum += head->val;
            mp[sum] = head;
            head = head->next;
        }
        sum = 0;
        head = newHead;
        while(head) {
            sum += head->val;
            head->next = mp[sum]->next;
            head = head->next;
        }
        return newHead->next;
    }
};