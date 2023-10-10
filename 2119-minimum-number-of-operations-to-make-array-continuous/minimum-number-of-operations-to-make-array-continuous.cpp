class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 1e9, n = nums.size();
        set<int> st(nums.begin(), nums.end());
        nums.clear();
        for(int num : st) {
            nums.push_back(num);
        }
        for(int i = 0; i < nums.size(); i++) {
            int target = nums[i] + n - 1;
            int rightIdx = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            int cost = n - (rightIdx - i);
            result = min(result, cost);
        }
        return result;
    }
};