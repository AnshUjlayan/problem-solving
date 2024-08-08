class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int x, int y) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<vector<int>> result;
        vector<int> dirs {0, 1, 0, -1};
        int dard = rows * cols;
        int dirX = 0, dirY = 1;
        int steps = 0, rem = 1;
        bool flip = false;

        auto valid = [&rows, &cols] (int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < rows && j < cols;
        };

        while (dard) {
            if (valid(x, y)) {
                result.push_back({x, y});
                dard--;
            }
            x += dirs[dirX];
            y += dirs[dirY];
            
            if (++steps == rem) {
                steps = 0;
                rem += flip;
                flip = !flip;
                dirX = (dirX + 1) % 4;
                dirY = (dirY + 1) % 4;
            }
        }

        return result;
    }
};