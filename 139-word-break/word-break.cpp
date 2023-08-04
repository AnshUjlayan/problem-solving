class Solution {
private:
    bool func(unordered_map<int,bool>& dp, string& s, unordered_set<string>& wordSet, int idx) {
        if(idx == s.size()) {
            return true;
        }
        if(dp.find(idx) != dp.end())
            return dp[idx];
        string ans = "";
        bool result = false;
        int slime = idx;
        while(!result && idx < s.size()) {
            ans += s[idx++];
            if(wordSet.find(ans) != wordSet.end() && func(dp, s, wordSet, idx)) {
                result = true;
            }
        }
        return dp[slime] = result;
    }
public:
    bool wordBreak(string& s, vector<string>& wordDict) {
        unordered_map<int,bool> dp;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return func(dp, s, wordSet, 0);
    }
};