class Solution {
public:
    long long minimumSteps(string s) {
        long long result = 0;
        int n = s.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += s[i] == '0';
            result += s[i] == '0' ? i : 0;
        }
        while (cnt--)
            result -= cnt;
        return result;
    }
};