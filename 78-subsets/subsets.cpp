class Solution {
private:
    set<vector<int>> result;
    void slime(vector<int>& nums, vector<int>& subset, int idx) {
        if(idx == nums.size()) {
            if(!result.count(subset)) {
                result.insert(subset);
            }
            return;
        }
        slime(nums, subset, idx + 1);
        subset.push_back(nums[idx]);
        slime(nums, subset, idx + 1);
        subset.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        slime(nums, subset, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }
};