class Solution {
private:
    int func(vector<int>& cuts, int (&dp)[101][101], int left, int right, int idxl, int idxr) {
        if(idxl > idxr) {
            return 0;
        }
        if(dp[idxl][idxr] != -1) {
            return dp[idxl][idxr];
        }
        int minDiff = INT_MAX;
        for(int i = idxl; i <= idxr; i++) {
            minDiff = min(minDiff, (right - left) + func(cuts, dp, left, cuts[i], idxl, i - 1) + func(cuts, dp, cuts[i], right, i + 1, idxr));
        }
        return dp[idxl][idxr] = minDiff;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        return func(cuts, dp, 0, n, 0, cuts.size() - 1);
    }
};