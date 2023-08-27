class Solution {
private:
    unordered_map<int,int> stoneIdx;
    int dp[2001][2001];
    bool func(vector<int>& stones, int idx, int k) {
        if(idx == stones.size() - 1) {
            return true;
        }
        if(dp[idx][k] != -1) {
            return dp[idx][k];
        }
        dp[idx][k] = 0;
        for(int i = -1; i < 2; i++) {
            if(k + i > 0 && stoneIdx.find(stones[idx] + k + i) != stoneIdx.end()) {
                dp[idx][k] = dp[idx][k] || func(stones, stoneIdx[stones[idx] + k + i], k + i);
            }
        }
        return dp[idx][k];
    }
public:
    bool canCross(vector<int>& stones) {
        for(int i = 0; i < stones.size(); i++) {
            stoneIdx[stones[i]] = i;
        }
        memset(dp, -1, sizeof(dp));
        return func(stones, 0, 0);
    }
};