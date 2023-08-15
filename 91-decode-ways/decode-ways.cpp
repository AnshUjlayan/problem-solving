class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        unordered_set<string> ust;
        for(int i = 1; i <= 26; i++) {
            ust.insert(to_string(i));
        }
        function<int(int)> func = [&](int idx) {
            if(idx == s.size()) {
                return 1;
            }
            if(dp[idx] != -1) {
                return dp[idx];
            }
            int ans = 0;
            if(ust.find(s.substr(idx, 1)) != ust.end()) {
                ans += func(idx + 1);
            }
            if(idx + 1 < s.size() && ust.find(s.substr(idx, 2)) != ust.end()) {
                ans += func(idx + 2);
            }
            return dp[idx] = ans;
        };
        return func(0);
    }
};