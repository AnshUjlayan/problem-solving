class Solution {
public:
    int numSteps(string s) {
        int result = 0, offset = 0, i = s.size();
        while(--i) {
            if(offset + (s[i] - '0') == 1) {
                offset = 1;
                result++;
            }
            result++;
        }
        return result + offset;
    }
};