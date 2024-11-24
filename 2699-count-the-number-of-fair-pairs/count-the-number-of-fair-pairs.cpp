class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long result = 0;
        for (int i = 0; i < n; i++) {
            int l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int r = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            result += r - l;
        }
        return result;
    }
};