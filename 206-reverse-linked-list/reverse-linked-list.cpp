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
    ListNode* result = nullptr;
    ListNode* reverse(ListNode* head) {
        if(!head->next) {
            result = head;
            return head;
        }
        ListNode* temp = reverse(head->next);
        head->next = nullptr;
        temp->next = head;
        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        reverse(head);
        return result;
    }
};