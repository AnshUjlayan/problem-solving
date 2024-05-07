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
private:
    int getSlimy(ListNode* head) {
        if(!head) return 0;
        int oldVal = head->val;
        int offset = getSlimy(head->next);
        head->val = (oldVal * 2 + offset) % 10;
        return (oldVal * 2 + offset) / 10;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        head = new ListNode(0, head);
        getSlimy(head);
        if(head->val) return head;
        return head->next;
    }
};