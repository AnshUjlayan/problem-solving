class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0), result(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }
        for(int i = 0; i < n; i++) {
            int left = abs(prefixSum[i] - ((i + 1) * nums[i]));
            int right = abs((prefixSum[n - 1] - prefixSum[i]) - ((n - i - 1) * nums[i]));
            result[i] = left + right;
        }
        return result;
    }
};