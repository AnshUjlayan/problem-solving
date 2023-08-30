class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target & 1) {
            return false;
        }
        target /= 2;
        unordered_set<int> dp;
        dp.insert(0);
        for(int& num : nums) {
            unordered_set<int> nextDp = dp;
            for(auto& val : dp) {
                nextDp.insert(num + val);
            }
            dp = nextDp;
        }
        return dp.find(target) != dp.end();
    }
};