class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX, l = 0, r = 0, sum = 0;
        while(r < nums.size()) {
            sum += nums[r];
            while(sum - nums[l] >= target) {
                sum -= nums[l];
                l++;
            }
            if(sum >= target)
                result = min(result, r - l + 1);
            r++;
        }
        return result == INT_MAX ? 0 : result;
    }
};