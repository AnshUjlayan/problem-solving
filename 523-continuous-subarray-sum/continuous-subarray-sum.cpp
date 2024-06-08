class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        map<int, int> mp{{0, -1}};
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % k;
            if (mp.count(sum) && mp[sum] < i - 1)
                return true;
            if (!mp.count(sum))
                mp[sum] = i;
        }
        return false;
    }
};