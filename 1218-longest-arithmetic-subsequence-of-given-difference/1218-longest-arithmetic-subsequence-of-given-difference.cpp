class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), result = 0;
        unordered_map<int,int> dp;
        for(int i = 0; i < n; i++) {
            dp[arr[i]] = 1 + (dp.count(arr[i] - difference) ? dp[arr[i] - difference] : 0);
            result = max(result, dp[arr[i]]);
        }
        return result;
    }
};