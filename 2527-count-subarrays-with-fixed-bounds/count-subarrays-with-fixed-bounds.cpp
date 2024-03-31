class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        int out = -1, lower = -1, upper = -1;
        long long result = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == minK) {
                lower = i;
            }
            if(nums[i] == maxK) {
                upper = i;
            }
            if(nums[i] < minK || nums[i] > maxK) {
                out = i;
            }
            int left = min(lower, upper);
            if(out < left) {
                result += left - out;
            }
        }
        return result;
    }
};