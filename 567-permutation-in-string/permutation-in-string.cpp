class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if (s1.size() > s2.size()) return false;
        int need = 0, map[26] = {0};
        int l = 0, r = s1.size(), n = s2.size();
        for (int i = 0; i < r; i++) {
            need += map[s1[i] - 97]++ ? 0 : 1;
            need -= --map[s2[i] - 97] ? 0 : 1;
        }
        while (r < n) {
            if (!need) return true;
            need -= --map[s2[r++] - 97] ? 0 : 1;
            need += map[s2[l++] - 97]++ ? 0 : 1;
        }
        return !need;
    }
};