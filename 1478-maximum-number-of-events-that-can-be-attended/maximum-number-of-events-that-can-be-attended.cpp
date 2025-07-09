class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(events.begin(), events.end());
        int res = 0, curr = 1;
        int i = 0, n = events.size();
        priority_queue<pair<int,int>> pq;
        while (!pq.empty() || i < n) {
            while (i < n && events[i][0] <= curr) {
                pq.push({-events[i][1], events[i][0]});
                i++;
            }
            while (!pq.empty() && -pq.top().first < curr) {
                pq.pop();
                continue;
            }
            if (!pq.empty()) {
                res++;
                pq.pop();
            }
            curr++;
        }
        return res;
    }
};