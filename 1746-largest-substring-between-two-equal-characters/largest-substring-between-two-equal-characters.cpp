class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size(), result = -1;
        vector<int> chars(26, -1);
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if(chars[c] != -1) {
                result = max(result, i - chars[c] - 1);
            }
            else {
                chars[c] = i;
            }
        }
        return result;
    }
};