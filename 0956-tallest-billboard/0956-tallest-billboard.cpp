class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = 0, n = rods.size();
        unordered_map<int,int> dp;
        dp[0] = 0;
        for(int& rod : rods) {
            unordered_map<int,int> temp = dp;
            for(auto& [diff, taller] : dp) {
                temp[diff + rod] = max(temp[diff + rod], taller + rod);
                temp[abs(diff - rod)] = max(temp[abs(diff - rod)], max(taller, taller - diff + rod));
            }
            dp = temp;
        }
        return dp[0];
    }
};