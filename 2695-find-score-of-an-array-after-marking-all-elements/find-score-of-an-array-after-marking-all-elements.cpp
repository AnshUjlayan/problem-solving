class Solution {
public:
    long long findScore(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            return a.first == b.first ? a.second > b.second : a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        long long result = 0;
        while (!pq.empty()) {
            while (!pq.empty() && nums[pq.top().second] == -1) {
                pq.pop();
            }
            if (!pq.empty()) {
                result += pq.top().first;
                if (pq.top().second > 0) {
                    nums[pq.top().second - 1] = -1;
                }
                if (pq.top().second < nums.size() - 1) {
                    nums[pq.top().second + 1] = -1;
                }
                pq.pop();
            }
        }
        return result;
    }
};