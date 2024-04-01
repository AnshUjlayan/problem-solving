class Solution {
public:
    int lengthOfLastWord(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int res = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ' ') {
                if(!res) {
                    continue;
                }
                else {
                    break;
                }
            }
            res++;
        }
        return res;
    }
};