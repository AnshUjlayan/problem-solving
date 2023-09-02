class Solution {
private:
    int func(unordered_set<string>& dict, vector<int>& dp, string s, int l) {
        int result = INT_MAX;
        for(int r = l; r < s.size(); r++) {
            string currStr = s.substr(l, r - l + 1);
            if(dict.find(currStr) != dict.end()) {
                result = min(result, dp[r + 1]);
            }
        }
        return result;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1);
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        for(int i = n - 1; i >= 0; i--) {
            dp[i] = min({dp[i + 1] + 1, func(dict, dp, s, i)});
        }
        return dp[0];
    }
};