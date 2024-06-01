class Solution {
public:
    int scoreOfString(string s) {
        int result = 0, n = s.size();
        for(int i = 0; i < n - 1; i++) {
            result += abs(s[i] - s[i + 1]);
        }
        return result;
    }
};