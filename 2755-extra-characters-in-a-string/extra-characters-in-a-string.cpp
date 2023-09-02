class Solution {
private:
    int calc(vector<int>& dp, string str, string s, int i) {
        int idx = 0, len = str.size();
        if(s.size() < str.size() || str != s.substr(i, len)) {
            return INT_MAX;
        }
        return dp[i + len];
    }
    int func(vector<string>& dictionary, vector<int>& dp, string s, int i) {
        int result = INT_MAX;
        for(auto& str : dictionary) {
            result = min(result, calc(dp, str, s, i));
        }
        return result;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--) {
            dp[i] = min({dp[i + 1] + 1, func(dictionary, dp, s, i)});
        }
        return dp[0];
    }
};