class Solution {
private:
    void func(vector<vector<int>>& result, vector<int>& ans, vector<int>& nums) {
        if(ans.size() == nums.size()) {
            result.push_back(ans);
            return;
        }
        for(int& num : nums) {
            if(find(ans.begin(), ans.end(), num) == ans.end()) {
                ans.push_back(num);
                func(result, ans, nums);
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        func(result, ans, nums);
        return result;
    }
};