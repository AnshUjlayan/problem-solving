class Solution {
public:
    string minRemoveToMakeValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        string str = "";
        stack<char> stk;
        for(char& c : s) {
            if(c == '(') {
                stk.push(c);
            }
            else if(c == ')') {
                if(!stk.empty() && stk.top() == '(') {
                    stk.pop();
                }
                else {
                    continue;
                }
            }
            str += c;
        }
        string result = "";
        reverse(str.begin(), str.end());
        for(char& c : str) {
            if(!stk.empty() && c == '(') {
                stk.pop();
                continue;
            }
            result += c;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};