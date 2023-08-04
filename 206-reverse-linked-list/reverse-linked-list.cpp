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
    ListNode* result;
    ListNode* func(ListNode* head) {
        if(!head->next) {
            result = head;
            return head;
        }
        ListNode* temp = func(head->next);
        temp->next = head;
        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        func(head);
        head->next = nullptr;
        return result;
    }
};