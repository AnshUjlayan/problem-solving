class Solution {
public:
    int minSwaps(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size(), ones = 0;
        for (int i = 0; i < n; i++) {
            ones += nums[i];
            nums.push_back(nums[i]);
        }

        int l = 0, r = 0, cnt = 0, result = 0;
        while (r < nums.size()) {
            cnt += nums[r++];
            if (r - l > ones) {
                cnt -= nums[l++];
            }
            result = max(result, cnt);
        }
        
        return ones - result;
    }
};