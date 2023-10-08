class Solution {
private:
    int func(vector<vector<int>>& dp, vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i == nums1.size() || j == nums2.size()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int pick = (nums1[i] * nums2[j]) + func(dp, nums1, nums2, i + 1, j + 1);
        int skip1 = func(dp, nums1, nums2, i + 1, j);
        int skip2 = func(dp, nums1, nums2, i, j + 1);
        return dp[i][j] = max({pick, skip1, skip2});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int min1 = *min_element(nums1.begin(), nums1.end());
        int min2 = *min_element(nums2.begin(), nums2.end());
        int max1 = *max_element(nums1.begin(), nums1.end());
        int max2 = *max_element(nums2.begin(), nums2.end());
        if(max1 < 0 && min2 > 0) {
            return max1 * min2;
        }
        if(min1 > 0 && max2 < 0) {
            return min1 * max2;
        }
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        return func(dp, nums1, nums2, 0, 0);
    }
};