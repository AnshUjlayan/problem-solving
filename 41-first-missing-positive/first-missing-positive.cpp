class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size(), result = 1;
        for(int& num : nums) {
            while(num > 0 && num <= n && num != nums[num - 1]) {
                swap(num, nums[num - 1]);
            }
        }
        for(int& num : nums) {
            if(num > 0) {
                if(num != result) {
                    return result;
                }
                result++;
            }
        }
        return result;
    }
};