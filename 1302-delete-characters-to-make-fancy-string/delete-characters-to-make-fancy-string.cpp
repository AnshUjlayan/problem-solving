class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        char prev = '\0';
        int cnt = 0;
        for (char &c : s) {
            if (c == prev) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt < 3) {
                res += c;
            }
            prev = c;
        }
        return res;
    }
};