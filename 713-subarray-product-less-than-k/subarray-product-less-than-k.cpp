class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(k <= 1) return 0;
        int l = 0, r = 0, n = nums.size();
        int result = 0, prod = 1;
        while(r < n) {
            prod *= nums[r++];
            while(prod >= k) {
                prod /= nums[l++];
            }
            result += r - l;
        }
        return result;
    }
};