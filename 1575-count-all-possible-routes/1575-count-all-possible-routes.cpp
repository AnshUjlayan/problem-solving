class Solution {
private:
    int mod = 1e9 + 7;
    int func(vector<vector<int>>& dp, vector<int>& locations, int& finish, int fuel, int curr) {
        if(fuel < 0)
            return 0;
        if(dp[curr][fuel] != -1)
            return dp[curr][fuel];
        int result = 0;
        if(curr == finish)
            result++;
        for(int i = 0; i < locations.size(); i++) {
            if(curr == i)
                continue;
            result = (result + func(dp, locations, finish, fuel - abs (locations[curr] - locations[i]), i)) % mod;
        }
        return dp[curr][fuel] = result;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(), vector<int>(fuel + 1, -1));
        return func(dp, locations, finish, fuel, start);
    }
};