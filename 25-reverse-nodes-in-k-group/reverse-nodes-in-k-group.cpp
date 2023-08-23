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
    void reverse(ListNode*& head, int k) {
        ListNode* curr = head;
        ListNode* prev = head;
        while(k) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            k--;
        }
        head->next = nullptr;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int have = 1;
        while(curr && have < k) {
            curr = curr->next;
            have++;
        }
        if(!curr) {
            return head;
        }
        ListNode* nextRev = reverseKGroup(curr->next, k);
        reverse(head, k);
        head->next = nextRev;
        return curr;
    }
};