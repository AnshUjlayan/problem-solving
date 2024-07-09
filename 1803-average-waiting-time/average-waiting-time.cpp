class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long wait = 0;
        int t = 0;
        for (auto& cust : customers) {
            t = max(t, cust[0]);
            t += cust[1];
            wait += t - cust[0];
        }
        return static_cast<double>(wait) / customers.size();
    }
};