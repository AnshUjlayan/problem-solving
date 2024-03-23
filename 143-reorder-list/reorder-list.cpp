class Solution {
public:
    ListNode* reorderList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<ListNode*> nodes, result;
        while(head) {
            nodes.push_back(head);
            head = head->next;
        }
        int n = nodes.size(), start = 0, end = nodes.size() - 1;
        while(start <= end) {
            result.push_back(nodes[start++]);
            result.push_back(nodes[end--]);
        }
        for(int i = 0; i < n - 1; i++) {
            result[i]->next = result[i + 1];
        }
        result[n - 1]->next = nullptr;
        return result[0];
    }
};