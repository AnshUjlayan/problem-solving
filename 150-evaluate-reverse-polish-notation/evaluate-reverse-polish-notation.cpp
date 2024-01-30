class Solution {
private:
    bool is_digit(const std::string& s) {
        return std::isdigit(s[0]) || (s[0] == '-' && s.size() > 1 && std::isdigit(s[1]));
    }
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stk;
        for (const std::string& token : tokens) {
            if (is_digit(token)) {
                stk.push(std::stoi(token));
            } else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                switch (token[0]) {
                    case '/':
                        stk.push(a / b);
                        break;
                    case '*':
                        stk.push(a * b);
                        break;
                    case '+':
                        stk.push(a + b);
                        break;
                    case '-':
                        stk.push(a - b);
                        break;
                }
            }
        }
        return stk.top();
    }
};
