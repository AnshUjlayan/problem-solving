class Solution {
private:
    struct Item {
        int original, val, div;
        Item(int val) : original(val), val(val), div(1) {}
    };

    struct ItemComparator {
        bool operator()(Item* a, Item* b) {
            return a->val < b->val;
        }
    };

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        priority_queue<Item*, vector<Item*>, ItemComparator> pq;
        for (int &q : quantities) {
            pq.push(new Item(q));
        }
        n -= quantities.size();
        while (n--) {
            auto top = pq.top();
            pq.pop();
            top->div++;
            top->val = (top->original + top->div - 1) / top->div;
            pq.push(top);
        }
        return pq.top()->val;
    }
};