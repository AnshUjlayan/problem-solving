class Solution {
public:
    bool isIsomorphic(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> map1(128, -1), map2(128, -1);
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if((map1[s[i]] != -1 && map1[s[i]] != t[i]) || (map2[t[i]] != -1 &&  map2[t[i]] != s[i])) {
                return false;
            }
            map1[s[i]] = t[i];
            map2[t[i]] = s[i];
        }
        return true;
    }
};