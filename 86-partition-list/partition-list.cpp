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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode();
        ListNode* moreHead = new ListNode();
        ListNode* lessTail = lessHead;
        ListNode* moreTail = moreHead;
        ListNode* curr = head;
        while(curr) {
            if(curr->val < x) {
                lessTail->next = curr;
                lessTail = lessTail->next;
            }
            else {
                moreTail->next = curr;
                moreTail = moreTail->next;
            }
            curr = curr->next;
        }
        lessHead = lessHead->next;
        moreHead = moreHead->next;
        if(lessTail)
            lessTail->next = moreHead;
        if(moreTail)
            moreTail->next = nullptr;
        if(!lessHead) {
            return moreHead;
        }
        return lessHead;
    }
};