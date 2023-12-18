class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int mini1 = 1e4, mini2 = 1e4;
        for(int i = 0; i < n; i++) {
            if(nums[i] < mini1) {
                mini1 = max(mini2, nums[i]);
                mini2 = min(mini2, nums[i]);
            }
        }
        int maxi1 = -1e4, maxi2 = -1e4;
        for(int i = 0; i < n; i++) {
            if(nums[i] > maxi1) {
                maxi1 = min(maxi2, nums[i]);
                maxi2 = max(maxi2, nums[i]);
            }
        }
        return (maxi1 * maxi2) - (mini1 * mini2);
    }
};