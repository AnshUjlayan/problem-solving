class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        long long result = 0;
        vector<long long> prefix(n, 0), postfix(n, 0);
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] | nums[i - 1];
        }
        for(int i = n - 2; i >= 0; i--) {
            postfix[i] = postfix[i + 1] | nums[i + 1];
        }
        for(int i = 0; i < n; i++) {
            long long temp = ((long long)nums[i] << k);
            long long res = temp | prefix[i] | postfix[i];
            result = max(result, res);
        }
        return result;
    }
};