class Solution {
private:
    void func(vector<vector<int>>& result, vector<int>& permutation, vector<bool>& picked, vector<int>& nums, int remaining) {
        if(remaining == 0) {
            result.push_back(permutation);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!picked[i]) {
                permutation.push_back(nums[i]);
                picked[i] = true;
                func(result, permutation, picked, nums, remaining - 1);
                permutation.pop_back();
                picked[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        vector<bool> picked(nums.size(), false);
        func(result, permutation, picked, nums, nums.size());
        return result;
    }
};