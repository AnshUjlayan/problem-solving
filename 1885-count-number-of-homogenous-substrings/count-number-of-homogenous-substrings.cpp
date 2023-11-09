class Solution {
public:
    int countHomogenous(string s) {
        long long result = 0;
        int n = s.size(), mod = 1e9 + 7, l = 0, r = 0;
        while(r < n) {
            if(s[r++] != s[l]) {
                result += 1ll * (r - l) * (r - l - 1) / 2;
                result %= mod;
                l = r - 1;
            }
        }
        result += 1ll * (r - l) * (r - l + 1) / 2;
        result %= mod;
        return (int)result;
    }
};