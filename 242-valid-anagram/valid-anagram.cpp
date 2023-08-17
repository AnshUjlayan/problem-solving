class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> ump;
        for(int i = 0; i < s.size(); i++) {
            ump[s[i]]++;
            ump[t[i]]--;
            if(ump[t[i]] == 0) {
                ump.erase(t[i]);
            }
            if(ump[s[i]] == 0) {
                ump.erase(s[i]);
            }
        }
        return s.size() == t.size() && ump.empty();
    }
};