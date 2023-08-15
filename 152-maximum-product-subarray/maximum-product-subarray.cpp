class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN, n = nums.size(), low = 1, high = 1;
        for(int i = 0; i < n; i++) {
            int temp = nums[i] * high;
            high = max({nums[i], temp, nums[i] * low});
            low = min({nums[i], temp, nums[i] * low});
            result = max(result, high);
        }
        return result;
    }
};