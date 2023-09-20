class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int result = -1, sum = accumulate(nums.begin(), nums.end(), 0) - x;
        int windowSum = 0, l = 0, r = 0;
        while(r < nums.size()) {
            sum -= nums[r++];
            while(l < r && sum < 0) {
                sum += nums[l++];
            }
            if(sum == 0) {
                result = max(result, r - l);
            }
        }
        return result == -1 ? -1 : nums.size() - result;
    }
};