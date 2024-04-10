class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(deck.rbegin(), deck.rend());
        vector<int>::iterator it = deck.begin();
        deque<int> dq {*it++};
        while(it != deck.end()) {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(*it++);
        }
        return vector<int>(dq.begin(), dq.end());
    }
};
