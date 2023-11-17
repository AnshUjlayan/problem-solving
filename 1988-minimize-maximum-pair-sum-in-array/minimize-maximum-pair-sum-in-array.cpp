class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int result = -1e9;
        while(l < r) {
            result = max(result, nums[l++] + nums[r--]);
        }
        return result;
    }
};