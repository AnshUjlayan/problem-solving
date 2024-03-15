class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prod = 1;
        vector<int> result(n);
        for(int i = n - 1; i >= 0; i--) {
            result[i] = prod;
            prod *= nums[i];
        }
        prod = 1;
        for(int i = 0; i < n; i++) {
            result[i] = prod * result[i];
            prod *= nums[i];
        }
        return result;
    }
};