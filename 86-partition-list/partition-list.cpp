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
        ListNode* lessHead = nullptr;
        ListNode* moreHead = nullptr;
        ListNode* lessTail = nullptr;
        ListNode* moreTail = nullptr;
        ListNode* curr = head;
        while(curr) {
            if(curr->val < x) {
                lessHead = lessTail = curr;
                break;
            }
            curr = curr->next;
        }
        curr = head;
        while(curr) {
            if(curr->val >= x) {
                moreHead = moreTail = curr;
                break;
            }
            curr = curr->next;
        }
        curr = head;
        while(curr) {
            if(curr == lessHead || curr == moreHead) {
                curr = curr->next;
                continue;
            }
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