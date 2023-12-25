class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 2, 0);
        dp[n] = 1, dp[n + 1] = 1;
        dp[n - 1] = s[n - 1] != '0' ? 1 : 0;
        for(int i = n - 2; i >= 0; i--) {
            if(s[i] == '0') {
                continue;
            }
            if(dp[i + 1] != 0) {
                dp[i] += dp[i + 1];
            }
            if(dp[i + 2] != 0 && ((s[i] == '2' && s[i + 1] <= '6') || (s[i] == '1'))) {
                dp[i] += dp[i + 2];
            }
        }
        for(int d : dp) {
            cout<<d<<" ";
        }
        return dp[0];
    }
};
