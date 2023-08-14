class Solution {
public:
    int rob(vector<int>& nums) {
        int a = nums[nums.size() - 1], b = 0;
        for(int i = nums.size() - 2; i >= 0; i--) {
            int temp = max(nums[i] + b, a);
            b = a;
            a = temp;
        }
        return a;
    }
};