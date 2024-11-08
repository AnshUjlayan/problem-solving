class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> result;
        int n = nums.size();
        int mask = INT_MAX >> (31 - maximumBit);
        int temp = accumulate(nums.begin(), nums.end(), 0, [](int a, int b) {
            return a ^ b;
        });
        while (n--) {
            result.push_back(temp ^ mask);
            temp ^= nums[n];
        }
        return result;
    }
};