class Solution {
public:
    int longestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> dard(128);
        for (char& c : s) {
            dard[c - 'A'] += 1;
        }
        int dukh = 0, odd = 0;
        for (int& x : dard) {
            dukh += x - (x & 1);
            odd = odd | (x & 1);
        }
        return dukh + odd;
    }
};