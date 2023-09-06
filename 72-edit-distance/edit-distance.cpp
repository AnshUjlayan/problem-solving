class Solution {
private:
    int func(vector<vector<int>>& dp, string& word1, string& word2, int i, int j) {
        if(i == word1.size()) {
            return word2.size() - j;
        }
        if(j == word2.size()) {
            return word1.size() - i;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(word1[i] == word2[j]) {
            return dp[i][j] = func(dp, word1, word2, i + 1, j + 1);
        }
        return dp[i][j] = 1 + min({func(dp, word1, word2, i + 1, j + 1), func(dp, word1, word2, i + 1, j), func(dp, word1, word2, i, j + 1)});
    }
public:
    int minDistance(string& word1, string& word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return func(dp, word1, word2, 0, 0);
    }
};