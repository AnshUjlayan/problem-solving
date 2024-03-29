class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        map<int,int> mp;
        int l = 0, r = 0, ct = 0;
        int result = 0, n = nums.size();
        while(r < n) {
            if(mp[nums[r++]]++ == k) {
                ct++;
            }
            while(ct) {
                ct -= --mp[nums[l++]] == k ? 1 : 0;
            }
            result = max(result, r - l);
        }
        return result;
    }
};