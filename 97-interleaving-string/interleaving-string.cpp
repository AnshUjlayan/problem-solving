class Solution {
private:
    bool func(vector<vector<vector<int>>>& dp, string& finalStr, string& s1, string& s2, int f, int a, int b) {
        if(a == s1.size() && b == s2.size()) {
            return true;
        }
        if(dp[f][a][b] != -1) {
            return dp[f][a][b];
        }
        bool p = false, q = false;
        if(a < s1.size() && s1[a] == finalStr[f]) {
            p = func(dp, finalStr, s1, s2, f + 1, a + 1, b);
        }
        if(b < s2.size() && s2[b] == finalStr[f]) {
            q = func(dp, finalStr, s1, s2, f + 1, a, b + 1);
        }
        return dp[f][a][b] = p || q;
    }
public:
    bool isInterleave(string& s1, string& s2, string& s3) {
        int a = s1.size(), b = s2.size(), c = s3.size();
        if(a + b != c) {
            return false;
        }
        vector<vector<vector<int>>> dp(c + 1, vector<vector<int>>(a + 1, vector<int>(b + 1, -1)));
        return func(dp, s3, s1, s2, 0, 0, 0);
    }
};