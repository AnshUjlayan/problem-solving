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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> ust(nums.begin(), nums.end());
        ListNode* result = new ListNode(0, head);
        ListNode* prev = result;
        while (prev) {
            while (head && ust.count(head->val))
                head = head->next;
            prev->next = head;
            prev = prev->next;
            if (head)
                head = head->next;
        }
        return result->next;
    }
};