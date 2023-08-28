class Solution {
private:
    void func(set<vector<int>>& result, vector<int>& subset, vector<int>& candidates, int target, int idx) {
        if(target == 0) {
            result.insert(subset);
            return;
        }
        if(idx == candidates.size() || target < 0) {
            return;
        }
        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            subset.push_back(candidates[i]);
            func(result, subset, candidates, target - candidates[i], i + 1);
            subset.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> result;
        vector<int> subset;
        func(result, subset, candidates, target, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }
};