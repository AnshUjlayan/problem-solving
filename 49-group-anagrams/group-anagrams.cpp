class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<vector<int>,vector<string>> mp;
        for(string s : strs) {
            vector<int> freq(26);
            for(char c : s) {
                freq[c - 'a']++;
            }
            mp[freq].push_back(s);
        }
        for(auto res : mp) {
            result.push_back(res.second);
        }
        return result;
    }
};