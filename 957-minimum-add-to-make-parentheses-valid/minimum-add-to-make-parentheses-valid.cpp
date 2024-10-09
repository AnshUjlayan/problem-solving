class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, closed = 0;
        for (char &c : s) {
            if (c == '(')
                open++;
            else
                if (open)
                    open--;
                else
                    closed++;
        }
        return open + closed;
    }
};