class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for (char &c : s) {
            if (c == 'B' && !stk.empty() && stk.top() == 'A') {
                stk.pop();
            } else if (c == 'D' && !stk.empty() && stk.top() == 'C') {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.size();
    }
};