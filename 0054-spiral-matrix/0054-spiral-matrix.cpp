class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size(), m = matrix[0].size(), dir = 1, i = 0, j = 0;
        int top = 0, down = n - 1, left = 0, right = m - 1;
        while(top <= down && left <= right) {
            if(dir == 1) {
                for(int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
                dir++;
            }
            else if(dir == 2) {
                for(int i = top; i <= down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
                dir++;
            }
            else if(dir == 3) {
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[down][i]);
                }
                down--;
                dir++;
            }
            else {
                for(int i = down; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
                dir = 1;
            }
        }
        return result;
    }
};