class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0, sum = 0;
        int l = 0, r = 0;
        while (r < nums.size()) {
            sum += nums[r++];
            while (sum * (r - l) >= k) {
                sum -= nums[l++];
            }
            res += r - l;
        }
        return res;
    }
};