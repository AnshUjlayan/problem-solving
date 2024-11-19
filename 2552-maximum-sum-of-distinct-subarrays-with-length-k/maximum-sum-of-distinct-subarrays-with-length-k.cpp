class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long long result = 0, sum = 0;
        int l = 0, r = 0;
        map<int,int> mp;
        while (r < nums.size()) {
            sum += nums[r];
            mp[nums[r++]]++;
            if (r - l == k) {
                if (mp.size() == k) {
                    result = max(result, sum);
                }
                sum -= nums[l];
                if (--mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
        }
        return result;
    }
};