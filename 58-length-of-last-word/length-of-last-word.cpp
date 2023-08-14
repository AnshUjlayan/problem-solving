class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0, idx = s.size() -1;
        while(s[idx] == ' ') {
            idx--;
        }
        for(int i = idx; i >= 0; i--) {
            if(s[i] == ' ') {
                break;
            }
            result++;
        }
        return result;
    }
};