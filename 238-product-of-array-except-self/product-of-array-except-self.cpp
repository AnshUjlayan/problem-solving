class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prod1 = 1, prod2 = 1;
        vector<int> result(n), prefix(n), postfix(n);
        for(int i = 0; i < n; i++) {
            prefix[i] = nums[i] * prod1;
            prod1 = prefix[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            postfix[i] = nums[i] * prod2;
            prod2 = postfix[i];
        }
        for(int i = 0; i < n; i++) {
            int left = i > 0 ? prefix[i - 1] : 1;
            int right = i < n - 1 ? postfix[i + 1] : 1;
            result[i] = left * right;
        }
        return result;
    }
};