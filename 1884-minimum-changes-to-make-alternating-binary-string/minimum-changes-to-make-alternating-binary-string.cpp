class Solution {
public:
    int minOperations(string s) {
        int one = 0, zero = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            int curr = s[i] - '0';
            if(i & 1) {
                one += curr;
                zero += 1 - curr;
            }
            else {
                one += 1 - curr;
                zero += curr;
            }
        }
        return min(one, zero);
    }
};