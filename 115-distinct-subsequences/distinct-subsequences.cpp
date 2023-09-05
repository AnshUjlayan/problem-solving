class Solution {
private:
    int func(vector<vector<int>>& dp, string& s, string& t, int idxS, int idxT) {
        if(idxT == t.size()) {
            return 1;
        }
        if(idxS == s.size()) {
            return 0;
        }
        if(dp[idxS][idxT] != -1) {
            return dp[idxS][idxT];
        }
        if(s[idxS] == t[idxT]) {
            return dp[idxS][idxT] = (func(dp, s, t, idxS + 1, idxT + 1) + func(dp, s, t, idxS + 1, idxT)) % (int)(1e9 + 7);
        }
        return dp[idxS][idxT] = func(dp, s, t, idxS + 1, idxT) % (int)(1e9 + 7);
    }
public:
    int numDistinct(string& s, string& t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return func(dp, s, t, 0, 0);
    }
};