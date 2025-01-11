class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> f(26, 0);
        int rem = 0;
        for (char &c : s) {
            f[c - 'a']++;
        }
        for (int &x : f) {
            rem += x % 2;

        }
        return rem <= k && s.size() >= k;
    }
};