class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int,int> mp;
        int rows = 0;
        for(int& num : nums) {
            rows = max(rows, ++mp[num]);
        }
        result.resize(rows);
        for(auto& [key, val] : mp) {
            for(int i = 0; i < val; i++) {
                result[i].push_back(key);
            }
        }
        return result;
    }
};