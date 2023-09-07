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
    ListNode* reverse(ListNode* head, int length) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr && length--) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tempHead = new ListNode(0);
        tempHead->next = head;
        head = tempHead;
        ListNode* start = nullptr;
        ListNode* end = nullptr;
        for(int i = 0; i <= right; i++) {
            if(i + 1 == left) {
                start = tempHead;
            }
            if(i == right) {
                end = tempHead->next;
            }
            tempHead = tempHead->next;
        }
        ListNode* temp = start->next;
        start->next = reverse(start->next, right - left + 1);
        temp->next = end;
        return head->next;
    }
};