class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        int result = 0, prev = nums[0] - 1;
        for(int& num : nums) {
            result += num > prev ? 0 : abs(prev + 1 - num);
            prev = max(prev + 1, num);
        }
        return result;
    }
};