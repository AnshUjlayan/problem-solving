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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int bit = 0;
        stack<int> stk, stk1, stk2;
        while(l1) {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            stk2.push(l2->val);
            l2 = l2->next;
        }
        while(!stk1.empty() || !stk2.empty()) {
            int x = 0, y = 0;
            if(!stk1.empty()) {
                x = stk1.top();
                stk1.pop();
            }
            if(!stk2.empty()) {
                y = stk2.top();
                stk2.pop();
            }
            int res = x + y + bit;
            bit = 0;
            if(res > 9) {
                bit = 1;
                res -= 10;
            }
            stk.push(res);
        }
        if(bit) {
            stk.push(1);
        }
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(!stk.empty()) {
            curr->next = new ListNode(stk.top());
            curr = curr->next;
            stk.pop();
        }
        return head->next;
    }
};