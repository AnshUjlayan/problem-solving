class Solution {
private:
    void func(vector<vector<int>>& result, vector<int>& subset, vector<int>& candidates, int target, int idx) {
        if(target == 0) {
            result.push_back(subset);
            return;
        }
        if(idx == candidates.size() || target < 0) {
            return;
        }
        func(result, subset, candidates, target, idx + 1);
        subset.push_back(candidates[idx]);
        func(result, subset, candidates, target - candidates[idx], idx);
        subset.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        func(result, subset, candidates, target, 0);
        return result;
    }
};