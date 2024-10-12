class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int result = 1e9, rem = 0, n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0ll) % p;
        if (!target) return 0;
        unordered_map<int,int> map {{0, -1}};
        for (int i = 0; i < n; i++) {
            rem = (rem + nums[i]) % p;
            int pain = (rem - target + p) % p;
            if (map.find(pain) != map.end())
            result = min(result, i - map[pain]);
            map[rem] = i;
        }
        return result < n ? result : -1;
    }
};