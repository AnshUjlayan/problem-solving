class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int idx = 0, n = nums.size();
        nums.push_back(1e9);
        while(idx < n) {
            if(nums[idx + 2] - nums[idx] > k) {
                return {};
            }
            result.push_back({nums[idx], nums[idx + 1], nums[idx + 2]});
            idx += 3;
        }
        return result;
    }
};