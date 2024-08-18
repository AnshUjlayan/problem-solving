class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size(), result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int one = 0, zero = 0;
                for (int k = i; k <= j; k++) {
                    one += s[k] - '0';
                    zero += !(s[k] - '0');
                }
                result += one <= k || zero <= k;
            }
        }
        return result;
    }
};