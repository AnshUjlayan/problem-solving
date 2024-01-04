class Solution {
private:
    vector<int> dp;
    int getSlimy(int n) {
        if(n == 0) {
            return 0;
        }
        if(n < 0) {
            return 1e6;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = 1 + min(getSlimy(n - 2), getSlimy(n - 3));
    }
public:
    int minOperations(vector<int>& nums) {
        this->dp.resize(1e6 + 1, -1);
        map<int,int> mp;
        int result = 0;
        for(int& num : nums) {
            mp[num]++;
        }
        for(auto& [key, val] : mp) {
            int calc = getSlimy(val);
            if(calc >= 1e6) {
                return -1;
            }
            result += calc;
        }
        return result;
    }
};