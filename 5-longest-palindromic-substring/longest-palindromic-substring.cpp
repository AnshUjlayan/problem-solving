class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        for(int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while(l >= 0 && r <= s.size() - 1 && s[l] == s[r]) {
                if(r - l + 1 > result.size()) {
                    result = s.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while(l >= 0 && r <= s.size() - 1 && s[l] == s[r]) {
                if(r - l + 1 > result.size()) {
                    result = s.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
        }
        return result;
    }
};