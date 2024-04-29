class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int res = 0;
        for(int& num : nums) {
            res ^= num;
        }
        res ^= k;
        return __builtin_popcount(res);
    }
};