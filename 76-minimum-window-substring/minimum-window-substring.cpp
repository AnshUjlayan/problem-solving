class Solution {
public:
    string minWindow(string s, string t) {
        int resLen = INT_MAX, resIdx = s.size() - 1, have = 0, need = 0, l = 0, r = 0;
        unordered_map<char,int> ump1, ump2;

        for(char c : t) {
            ump2[c]++;
            if(ump2[c] == 1) {
                need++;
            }
        }

        while(r < s.size()) {
            ump1[s[r]]++;
            if(ump1[s[r]] == ump2[s[r]]) {
                have++;
            }
            r++;
            while(need == have) {
                if(r - l < resLen) {
                    resLen = r - l;
                    resIdx = l;
                }
                ump1[s[l]]--;
                if(ump1[s[l]] == ump2[s[l]] - 1) {
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(resIdx, resLen);
    }
};