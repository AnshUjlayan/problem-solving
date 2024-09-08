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
    void getSlimy(vector<ListNode*> &result, ListNode *head, int seg, int &rem, int k) {
        if (!k)
            return;

        result.push_back(head);

        int cnt = seg;
        while (head && --cnt > 0)
            head = head->next;

        if (seg > 0 && rem-- > 0)
            head = head->next;

        ListNode* next = head ? head->next : nullptr;
        getSlimy(result, next, seg, rem, k - 1);

        if (head)
            head->next = nullptr;
    }

public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        ListNode *curr = head;
        int len = 0;
        while (curr) {
            curr = curr->next;
            len++;
        }

        int seg = len / k;
        int rem = len % k;

        getSlimy(result, head, seg, rem, k);
        return result;
    }
};