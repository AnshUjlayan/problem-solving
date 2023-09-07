class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, result = INT_MIN;
        for(int num : nums) {
            sum += num;
            result = max(result, sum);
            sum = sum < 0 ? 0 : sum;
        }
        return result;
    }
};