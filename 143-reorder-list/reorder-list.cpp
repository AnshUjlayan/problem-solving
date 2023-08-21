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
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while(head) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    void mergeLists(ListNode* head, ListNode* end) {
        while(end) {
            ListNode* tempStart = head->next;
            ListNode* tempEnd = end->next;
            head->next = end;
            end->next = tempStart;
            head = tempStart;
            end = tempEnd;
        }
    }
public:
    void reorderList(ListNode* head) {
        if(!head->next) {
            return;
        }
        ListNode* middle = getMiddle(head);
        ListNode* end = reverse(middle->next);
        middle->next = nullptr;
        mergeLists(head, end);
    }
};