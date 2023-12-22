class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), count = 0, result = 0;
        vector<int> zCount(n, 0);
        for(int i = 0; i < n; i++) {
            count += (s[i] == '0' ? 1 : 0);
            zCount[i] = count;
        }
        for(int i = 0; i < n - 1; i++) {
            int left = zCount[i];
            int right = n - i - 1 - (zCount[n - 1] - zCount[i]);
            result = max(result, left + right);
        }
        return result;
    }
};