class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        priority_queue<int,vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end());
        int result = 0;
        for (vector<int> &interval : intervals) {
            while (!pq.empty() && pq.top() < interval[0])
                pq.pop();
            pq.push(interval[1]);
            result = max(result, static_cast<int>(pq.size()));
        }
        return result;
    }
};