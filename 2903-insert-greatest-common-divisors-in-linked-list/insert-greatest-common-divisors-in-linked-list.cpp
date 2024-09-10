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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        ListNode* curr = head;
        while (curr->next) {
            curr->next = new ListNode(__gcd(curr->val, curr->next->val), curr->next);
            curr = curr->next->next;
        }
        return head;
    }
};