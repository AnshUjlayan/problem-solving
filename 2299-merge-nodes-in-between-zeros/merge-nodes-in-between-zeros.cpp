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
    ListNode* mergeNodes(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        ListNode* curr = head;
        while(curr) {
            ListNode* nxt = curr->next;
            while(nxt && nxt->val) {
                curr->val += nxt->val;
                nxt = nxt->next;
            }
            curr->next = nxt;
            curr = nxt;
        }
        curr = head;
        while (curr) {
            if (!curr->next->next) {
                curr->next = nullptr;
            }
            curr = curr->next;
        }
        return head;
    }
};