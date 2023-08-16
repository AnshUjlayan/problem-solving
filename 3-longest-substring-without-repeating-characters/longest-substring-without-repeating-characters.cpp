class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> ump;
        int result = 0, l = 0, r = 0;
        while(r < s.size()) {
            if(ump[s[r]] == 1) {
                ump[s[l++]]--;
                continue;
            }
            ump[s[r++]]++;
            result = max(result, r - l);
        }
        return result;
    }
};