class Solution {
private:
    bool func(vector<vector<int>>& dp, string& finalStr, string& s1, string& s2, int a, int b) {
        if(a + b == finalStr.size()) {
            return true;
        }
        if(dp[a][b] != -1) {
            return dp[a][b];
        }
        bool p = false, q = false;
        if(a < s1.size() && s1[a] == finalStr[a + b]) {
            p = func(dp, finalStr, s1, s2, a + 1, b);
        }
        if(b < s2.size() && s2[b] == finalStr[a + b]) {
            q = func(dp, finalStr, s1, s2, a, b + 1);
        }
        return dp[a][b] = p || q;
    }
public:
    bool isInterleave(string& s1, string& s2, string& s3) {
        int a = s1.size(), b = s2.size(), c = s3.size();
        if(a + b != c) {
            return false;
        }
        vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
        return func(dp, s3, s1, s2, 0, 0);
    }
};