class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0ll), res = 0;
        for (int i = 0; i < n - 1; i++) {
            sum -= nums[i] + nums[i];
            res += sum <= 0;
        }
        return res;
    }
};