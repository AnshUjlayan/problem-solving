class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
        dp[s.size()] = 1;
        unordered_set<string> ust;
        for(int i = 1; i <= 26; i++) {
            ust.insert(to_string(i));
        }
        for(int i = s.size() - 1; i >= 0; i--) {
            if(ust.find(s.substr(i, 1)) != ust.end()) {
                dp[i] += dp[i + 1];
            }
            if(i + 1 < s.size() && ust.find(s.substr(i, 2)) != ust.end()) {
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};