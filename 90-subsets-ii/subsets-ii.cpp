class Solution {
private:
    void func(set<vector<int>>& st, vector<int>& subset, vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            st.insert(subset);
            return;
        }
        func(st, subset, nums, idx + 1);
        subset.push_back(nums[idx]);
        func(st, subset, nums, idx + 1);
        subset.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<int> subset;
        func(st, subset, nums, 0);
        return vector<vector<int>>(st.begin(), st.end());
    }
};