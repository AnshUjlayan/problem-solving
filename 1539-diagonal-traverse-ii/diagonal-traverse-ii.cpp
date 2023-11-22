class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> result;
        map<int,vector<int>> mp;
        int m = nums.size();
        for(int i = 0; i < m; i++) {
            int n = nums[i].size();
            for(int j = 0; j < n; j++) {
                mp[i + j].push_back(nums[i][j]);
            }
        }
        for(auto& [key, diagonal] : mp) {
            for(int i = diagonal.size() - 1; i >= 0; i--) {
                result.push_back(diagonal[i]);
            }
        }
        return result;
    }
};