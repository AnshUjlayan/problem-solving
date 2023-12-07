class Solution {
public:
    string largestOddNumber(string num) {
        int idx = num.size();
        while(--idx >= 0) {
            if((num[idx] - '0') & 1) {
                break;
            }
        }
        return num.substr(0, idx + 1);
    }
};