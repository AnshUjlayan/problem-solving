class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 0, l = 0, r = 0, z = -1;
        while(r < nums.size()) {
            if(nums[r] == 0) {
                l = z + 1;
                z = r;
            }
            result = max(result, r - l);
            r++;
        }
        return result;
    }
};