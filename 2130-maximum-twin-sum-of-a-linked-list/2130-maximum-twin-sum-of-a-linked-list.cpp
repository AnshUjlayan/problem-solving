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
    void func(ListNode*& head, ListNode* curr, int& result, int n, int& len) {
        if(!curr) {
            len = n;
            return;
        }
        n++;
        func(head, curr->next, result, n, len);
        if(len < n) {
            return;
        }
        len--;
        result = max(result, curr->val + head->val);
        head = head->next;
    }
public:
    int pairSum(ListNode* head) {
        int result = 0, len = 0;
        func(head, head, result, 0, len);
        return result;
    }
};