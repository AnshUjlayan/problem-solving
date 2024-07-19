class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> maxNums(n, INT_MIN), result;

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                maxNums[j] = max(maxNums[j], matrix[i][j]);
            }
        }

        for (int i = 0; i < m; i++) {
            auto minElementIter = min_element(matrix[i].begin(), matrix[i].end());
            int mn = *minElementIter;
            int j = distance(matrix[i].begin(), minElementIter);
            if (mn == maxNums[j]) {
                result.push_back(mn);
            }
        }

        return result;
    }
};