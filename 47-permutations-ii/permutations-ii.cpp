class Solution {
private:
    void func(vector<bool>& picked, set<vector<int>>& result, vector<int>& subset, vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            result.insert(subset);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(picked[i]) {
                continue;
            }
            subset.push_back(nums[i]);
            picked[i] = true;
            func(picked, result, subset, nums, idx + 1);
            subset.pop_back();
            picked[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> picked(nums.size(), false);
        set<vector<int>> result;
        vector<int> subset;
        func(picked, result, subset, nums, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }
};