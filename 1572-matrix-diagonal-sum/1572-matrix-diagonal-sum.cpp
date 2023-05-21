class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), result = 0;
        for(int i = 0; i < n; i++) {
            result += mat[i][i];
            result += mat[n - 1 - i][i];
        }
        if(n % 2 != 0) {
            result -= mat[n/2][n/2];
        }
        return result;
    }
};