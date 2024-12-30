class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int result = 0, x = 0;
        priority_queue<int> pq;
        pq.push(0);
        for(int &val : values) {
            result = max(result, pq.top() - x + val);
            pq.push(val + x++);
        }
        return result;
    }
};