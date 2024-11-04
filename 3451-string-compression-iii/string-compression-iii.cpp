class Solution {
public:
    string compressedString(string word) {
        string result = "";
        int i = 0, n = word.size();
        while (i < n) {
            int cnt = 1;
            char c = word[i];
            while (i + 1 < n && word[i] == word[i + 1]) {
                cnt++;
                i++;
            }
            while (cnt > 0) {
                result += to_string(min(cnt, 9)) + c;
                cnt -= 9;
            }
            i++;
        }
        return result;
    }
};