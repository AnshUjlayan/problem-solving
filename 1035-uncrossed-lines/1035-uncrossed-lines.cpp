class Solution {
private:
    int func(vector<int>& nums1, vector<int>& nums2, int n, int m, vector<vector<int>>& dp, int i, int j) {
        if(i == n || j == m) {
            return 0;
        }
        else if(dp[i][j] != -1) {
            return dp[i][j];
        }
        else if(nums1[i] == nums2[j]) {
            return dp[i][j] = 1 + func(nums1, nums2, n , m, dp, i + 1, j + 1);
        }
        int x = func(nums1, nums2, n , m, dp, i, j + 1);
        int y = func(nums1, nums2, n , m, dp, i + 1, j);
        return dp[i][j] = max(x, y);
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int result = 0, n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(nums1, nums2, n , m, dp, 0, 0);
    }
};