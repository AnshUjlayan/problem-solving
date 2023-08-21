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
    ListNode* remove(ListNode* head, int& n) {
        if(!head) {
            n--;
            return nullptr;
        }
        head->next = remove(head->next, n);
        if(n == 0) {
            n--;
            return head->next;
        }
        n--;
        return head;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0);
        temp->next = remove(head, n);;
        remove(head, n);
        return temp->next;
    }
};