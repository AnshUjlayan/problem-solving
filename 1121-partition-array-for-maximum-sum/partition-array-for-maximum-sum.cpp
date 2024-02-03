class Solution {
private:
    vector<vector<int>> dp;
    int k;
    int getSlimy(vector<int>& arr, int len, int currMax, int idx) {
        if(len == k || idx == arr.size()) {
            return len * currMax;
        }
        if(dp[idx][len] != -1) {
            return dp[idx][len];
        }
        currMax = max(currMax, arr[idx]);
        int pick = getSlimy(arr, len + 1, currMax, idx + 1);
        int skip = ((len + 1) * currMax) + getSlimy(arr, 0, 0, idx + 1);
        return dp[idx][len] = max(pick, skip);
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->dp.resize(arr.size(), vector<int>(k, -1));
        this->k = k;
        return getSlimy(arr, 0, 0, 0);
    }
};