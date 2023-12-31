class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size(), result = -1;
        for(int i = 0; i < 26; i++) {
            char c = 'a' + i;
            int l = 0, r = n - 1;
            while(l < n && s[l] != c) {
                l++;
            }
            while(r >= 0 && s[r] != c) {
                r--;
            }
            result = max(result, r - l - 1);
        }
        return result;
    }
};