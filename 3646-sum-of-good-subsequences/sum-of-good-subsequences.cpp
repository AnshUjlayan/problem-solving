class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        long long result = 0, MOD = 1e9 + 7;
        int n = nums.size();
        unordered_map<int, long long> ump;
        vector<long long> left(n, 0), right(n, 0);
        for (int i = 0; i < n; i++) {
            ump[nums[i]] %= MOD;
            ump[nums[i]] += left[i] = (ump[nums[i] - 1] + ump[nums[i] + 1] + 1) % MOD;
        }
        ump.clear();
        for (int i = n - 1; i >= 0; i--) {
            ump[nums[i]] %= MOD;
            ump[nums[i]] += right[i] = (ump[nums[i] - 1] + ump[nums[i] + 1] + 1) % MOD;
        }
        for (int i = 0; i < n; i++) {
            long long comb = (1ll * left[i] * right[i]) % MOD;
            result += (comb * nums[i] % MOD) % MOD;
            result %= MOD;
        }
        return int(result);
    }
};