class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glass(102, vector<double>(101, 0.0));
        glass[0][0] = poured;
        for(int i = 0; i < query_row + 1; i++) {
            for(int j = 0; j < i + 1; j++) {
                double overflow = (glass[i][j] - 1.0) / 2.0;
                if(overflow > 0) {
                    glass[i + 1][j] += overflow;
                    glass[i + 1][j + 1] += overflow;
                }
            }
        }
        return min(1.0, glass[query_row][query_glass]);
    }
};