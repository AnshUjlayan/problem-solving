class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        function<bool(char, char)> match = [](char c1, char c2) {
            return c1 != c2 && tolower(c1) == tolower(c2);
        };
        for(char& c : s) {
            if(!stk.empty() && match(stk.top(), c)) {
                stk.pop();
            }
            else {
                stk.push(c);
            }
        }
        string str = "";
        while(!stk.empty()) {
            str += stk.top();
            stk.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};