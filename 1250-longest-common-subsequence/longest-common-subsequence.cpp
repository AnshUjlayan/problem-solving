class Solution {
private:
    vector<vector<int>> dp;
    int getSlimy(string& text1, string& text2, int i, int j) {
        if(i == text1.size() || j == text2.size()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(text1[i] == text2[j]) {
            return dp[i][j] = 1 + getSlimy(text1, text2, i + 1, j + 1);
        }
        return dp[i][j] = max(getSlimy(text1, text2, i + 1, j), getSlimy(text1, text2, i, j + 1));
    }
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        this->dp.resize(text1.size(), vector<int>(text2.size(), -1));
        return getSlimy(text1, text2, 0, 0);
    }
};