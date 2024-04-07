class Solution {
private:
    bool getSlimy(string s) {
        int open = 0, stars = 0;
        for(char& c : s) {
            if(c == '(') {
                open++;
            }
            else if(c == ')') {
                if(open) {
                    open--;
                }
                else if(stars) {
                    stars--;
                }
                else {
                    return false;
                }
            }
            else {
                stars++;
            }
        }
        return stars >= open;
    }
public:
    bool checkValidString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        string str = s;
        reverse(str.begin(), str.end());
        for(char& c : str) {
            if(c == '(') {
                c = ')';
            }
            else if(c == ')') {
                c = '(';
            }
        }
        return getSlimy(s) && getSlimy(str);
    }
};