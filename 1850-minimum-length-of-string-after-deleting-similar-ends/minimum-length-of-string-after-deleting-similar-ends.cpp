class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            char c = s[l];
            if(s[l] != s[r]) {
                break;
            }
            while(l <= r && s[l] == c) {
                l++;
            }
            while(l <= r && s[r] == c) {
                r--;
            }
        }
        return r - l + 1;
    }
};