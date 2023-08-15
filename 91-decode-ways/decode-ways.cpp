class Solution {
public:
    int numDecodings(string s) {
        unordered_set<string> ust;
        for(int i = 1; i <= 26; i++) {
            ust.insert(to_string(i));
        }
        int a = 1, b = 1;
        for(int i = s.size() - 1; i >= 0; i--) {
            int temp = 0;
            if(ust.find(s.substr(i, 1)) != ust.end()) {
                temp += a;
            }
            if(i + 1 < s.size() && ust.find(s.substr(i, 2)) != ust.end()) {
                temp += b;
            }
            b = a;
            a = temp;
        }
        return a;
    }
};