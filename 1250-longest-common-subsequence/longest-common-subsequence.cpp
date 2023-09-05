class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> dp(n + 1, 0);
        for(int i = m - 1; i >= 0; i--) {
            vector<int> nextDp = dp;
            for(int j = n - 1; j >= 0; j--) {
                nextDp[j] = max(nextDp[j + 1], dp[j]);
                if(text1[i] == text2[j]) {
                    nextDp[j] = 1 + dp[j + 1];
                }
            }
            dp = nextDp;
        }
        return dp[0];
    }
};