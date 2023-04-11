class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        string str = "";
        for(char c : s) {
            if(c == '*') {
                stk.pop();
            }
            else {
                stk.push(c);
            }
        }
        while(!stk.empty()) {
            str += stk.top();
            stk.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};