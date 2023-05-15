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
class Solution 
{
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        if(!head->next)
            return head;
        ListNode *temp1 = head, *temp2 = head;
        int count = 0;
        for(auto i = head; i; i = i->next) {
            count++;
            if(count == k)
                temp1 = i;
        }
        for(int i = 0; i < count - k; i++)
            temp2 = temp2->next;
        swap(temp1->val, temp2->val);
        return head;
    }
};