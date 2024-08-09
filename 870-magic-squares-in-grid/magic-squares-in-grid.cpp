class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        const int m = grid.size(), n = grid[0].size();
        int result = 0;

        auto bounds = [&m, &n] (const int &i, const int &j) -> bool {
            return i > 0 && j > 0 && i < m - 1 && j < n - 1;
        };

        auto valid = [&grid] (const int &i, const int &j) -> bool {
            vector<int> nums(16, 0);
            int sum = 0;

            for (int x = i - 1; x <= i + 1; x++) {
                sum = 0;
                for (int y = j - 1; y <= j + 1; y++) {
                    sum += grid[x][y];
                    nums[grid[x][y]] = 1;
                }
                if (sum != 15)
                    return false;
            }
            
            for (int y = j - 1; y <= j + 1; y++) {
                sum = 0;
                for (int x = i - 1; x <= i + 1; x++)
                    sum += grid[x][y];
                if (sum != 15)
                    return false;
            }

            int sum1 = 0, sum2 = 0;
            for (int z = -1; z <= 1; z++) {
                sum1 += grid[i + z][j + z];
                sum2 += grid[i + z][j - z];
            }

            if (sum1 != 15 || sum2 != 15)
                return false;

            return accumulate(nums.begin() + 1, nums.begin() + 10, 0) == 9;
        };

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (bounds(i, j))
                    result += valid(i, j);
        
        return result;
    }
};