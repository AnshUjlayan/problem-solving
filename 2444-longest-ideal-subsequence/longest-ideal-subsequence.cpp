class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> result(26, 0);
        for (char& c : s) {
            int l = max(0, c - 97 - k);
            int r = min(26, c - 97 + k + 1);
            result[c - 97] =
                *max_element(result.begin() + l, result.begin() + r) + 1;
        }
        return *max_element(result.begin(), result.end());
    }
};