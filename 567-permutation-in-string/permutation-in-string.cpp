class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> ump1, ump2;
        if(s1.size() > s2.size()) {
            return false;
        }
        for(int i = 0; i < s1.size(); i++) {
            ump1[s1[i]]++;
            ump2[s2[i]]++;
        }
        auto cmp = [&]() ->bool {
            for(int i = 0; i < 26; i++) {
                if(ump1['a' + i] != ump2['a' + i]) {
                    return false;
                }
            }
            return true;
        };
        int l = 0, r = s1.size();
        while(r < s2.size() && !cmp()) {
            ump2[s2[l++]]--;
            ump2[s2[r++]]++;
        }
        return cmp();
    }
};