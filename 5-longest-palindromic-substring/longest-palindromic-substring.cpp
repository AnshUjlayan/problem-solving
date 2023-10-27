class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string result = "";
        for(int i = 0; i < n; i++) {
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                l--, r++;
            }
            l++, r--;
            if(r - l + 1 > result.size()) {
                result = s.substr(l, r - l + 1);
            }
            if(i == n - 1) {
                break;
            }
            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                l--, r++;
            }
            l++, r--;
            if(r - l + 1 > result.size()) {
                result = s.substr(l, r - l + 1);
            }
        }
        return result;
    }
};