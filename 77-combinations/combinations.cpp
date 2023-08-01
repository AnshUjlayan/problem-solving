class Solution {
private:
    void func(vector<vector<int>>& result, vector<int>& ans, int& n, int k, int idx) {
        if(k == 0) {
            result.push_back(ans);
            return;
        }
        if(idx > n) {
            return;
        }
        func(result, ans, n, k, idx + 1);
        ans.push_back(idx);
        func(result, ans, n, k - 1, idx + 1);
        ans.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        vector<vector<int>> result;
        func(result, ans, n, k, 1);
        return result;
    }
};