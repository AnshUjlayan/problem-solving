class Solution {
public:
    int minDistance(string& word1, string& word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < n; i++) {
            dp[i] = n - i;
        }
        for(int i = m - 1; i >= 0; i--) {
            vector<int> nextDp = dp;
            nextDp[n]++;
            for(int j = n - 1; j >= 0; j--) {
                nextDp[j] = 1 + min({nextDp[j + 1], dp[j], dp[j + 1]});
                if(word1[i] == word2[j]) {
                    nextDp[j] = dp[j + 1];
                }
            }
            dp = nextDp;
        }
        return dp[0];
    }
};