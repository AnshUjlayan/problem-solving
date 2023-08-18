class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        unordered_map<char,char> pars = {{'{', '}'}, {'(', ')'}, {'[', ']'}};
        for(char c : s) {
            if(pars.find(c) != pars.end()) {
                stk.push(c);
            }
            else {
                if(stk.empty() || c != pars[stk.top()]) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};