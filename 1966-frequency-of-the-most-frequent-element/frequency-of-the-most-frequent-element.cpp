class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0;
        int prev = nums[0], sum = 0, result = 0;
        sort(nums.begin(), nums.end());
        while(r < n) {
            sum += 1ll * (r - l) * (nums[r] - prev);
            while(sum > k) {
                sum -= nums[r] - nums[l++];
            }
            result = max(result, r - l + 1);
            prev = nums[r++];
        }
        return result;
    }
};