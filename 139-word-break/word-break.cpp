class Solution {
private:
    bool func(unordered_map<string,bool>& dp, string s, vector<string>& wordDict) {
        if(s.empty()) {
            return true;
        }
        if(dp.find(s) != dp.end()) {
            return dp[s];
        }
        bool result = false;
        for(int i = 0; i <= s.size(); i++) {
            if(find(wordDict.begin(), wordDict.end(), s.substr(0, i)) != wordDict.end()) {
                result = result || func(dp, s.substr(i), wordDict);
            }
        }
        return dp[s] = result;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> dp;
        return func(dp, s, wordDict);
    }
};