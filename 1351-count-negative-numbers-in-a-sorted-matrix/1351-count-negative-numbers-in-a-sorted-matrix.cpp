class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0, len = grid[0].size();
        for(auto vec : grid) {
            int l = 0, r = len - 1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(vec[mid] < 0) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            result += len - l;
        }
        return result;
    }
};