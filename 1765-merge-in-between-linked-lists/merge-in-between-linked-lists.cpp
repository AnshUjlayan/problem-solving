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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        while(head) {
            if(--a == 0) {
                ListNode* temp = head->next;
                head->next = list2;
                head = temp;
            }
            if(b-- == 0) {
                while(list2 && list2->next) {
                    list2 = list2->next;
                }
                list2->next = head;
                break;
            }
            head = head->next;
        }
        return list1;
    }
};