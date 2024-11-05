class Solution {
public:
    int minChanges(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int result = 0, n = s.size();
        for (int i = 0; i < n; i += 2) {
            result += s[i] != s[i + 1];
        }
        return result;
    }
};