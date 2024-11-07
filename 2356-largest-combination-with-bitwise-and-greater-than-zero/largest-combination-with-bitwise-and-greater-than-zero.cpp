class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int result = 0, pos = 0;
        vector<int> bits(24, 0);
        for (int &num : candidates) {
            pos = 0;
            while (num) {
                bits[pos++] += num & 1;
                num >>= 1;
            }
        }
        for (int &bit : bits) {
            result = max(result, bit);
        }
        return result;
    }
};