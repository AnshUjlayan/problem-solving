class Solution {
private:
    int func(vector<int>& dp, vector<int>& days, vector<int>& costs, int idx) {
        if(idx == days.size()) {
            return 0;
        }
        if(dp[idx] != -1) {
            return dp[idx];
        }
        int day = costs[0] + func(dp, days, costs, idx + 1);
        int week = costs[1] + func(dp, days, costs, lower_bound(days.begin(), days.end(), days[idx] + 7) - days.begin());
        int month = costs[2] + func(dp, days, costs, lower_bound(days.begin(), days.end(), days[idx] + 30) - days.begin());
        return dp[idx] = min({day, week, month});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return func(dp, days, costs, 0);
    }
};