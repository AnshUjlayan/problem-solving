class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0, currMax = 0, l = 0, r = -1;
        unordered_map<char,int> ump;
        while(++r < s.size()) {
            ump[s[r]]++;
            currMax = max(currMax, ump[s[r]]);
            if((r - l + 1) - currMax > k) {
                ump[s[l++]]--;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};