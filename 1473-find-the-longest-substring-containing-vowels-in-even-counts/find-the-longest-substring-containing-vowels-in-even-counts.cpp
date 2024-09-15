class Solution {
public:
    int findTheLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = s.size(), bitmask = 0, result = 0;
        unordered_map<char, int> vow = {{'a', 1}, {'e', 2}, {'i', 4}, {'o', 8}, {'u', 16}};
        unordered_map<int, int> mp = {{0, -1}};
        for (int i = 0; i < n; i++) {
            bitmask ^= vow[s[i]];
            if (mp.find(bitmask) != mp.end()) {
                result = max(result, i - mp[bitmask]);
            } else {
                mp[bitmask] = i;
            }
        }
        return result;
    }
};