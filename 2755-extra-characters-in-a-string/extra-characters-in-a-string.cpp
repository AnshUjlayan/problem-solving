class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = s.size();
        vector<int> dp(n, INT_MAX);
        unordered_set<string> ust(dictionary.begin(), dictionary.end());
        string temp = "";
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            temp = "";
            for (int j = i; j < n; j++) {
                temp += s[j];
                dp[j] = min(dp[j], dp[i] + j - i);
                if (ust.count(temp)) {
                    dp[j] = min(dp[j], i > 0 ? dp[i - 1] : 0);
                }
            }
        }
        return dp[n - 1];
    }
};