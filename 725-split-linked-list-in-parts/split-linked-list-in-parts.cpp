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
    int getLength(ListNode* head) {
        ListNode* curr = head;
        int len = 0;
        while(curr) {
            len++;
            curr = curr->next;
        }
        return len;
    }
    ListNode* getGroup(ListNode* head, int groupSize, int& offset) {
        if(offset) {
            groupSize++;
            offset--;
        }
        while(head && groupSize--) {
            head = head->next;
        }
        ListNode* temp = head;
        if(head) {
            temp = head->next;
            head->next = nullptr;
        }
        return temp;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        int length = getLength(head);
        int groupSize = length / k - 1;
        int offset = length % k;
        while(k--) {
            result.push_back(head);
            ListNode* curr = getGroup(head, groupSize, offset);
            head = curr;
        }
        return result;
    }
};