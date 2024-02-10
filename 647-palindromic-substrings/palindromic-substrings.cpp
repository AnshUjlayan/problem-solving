class Solution {
public:
    int countSubstrings(string s) {
        int result = 0, n = s.size();
        function<void(int, int)> getSlimy = [&] (int l, int r) {
            while(l >= 0 && r < n) {
                if(s[l] != s[r]) {
                    return;
                }
                result++, l--, r++;
            }
        };
        for(int i = 0; i < n; i++) {
            getSlimy(i, i);
            getSlimy(i, i + 1);
        }
        return result;
    }
};