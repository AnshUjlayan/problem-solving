class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int dir = 1, num = 1, i = 0, j = 0;
        int top = 0, down = n - 1, left = 0, right = n - 1;
        while(top <= down && left <= right) {
            if(dir == 1) {
                for(int i = left; i <= right; i++) {
                    result[top][i] = num++;
                }
                top++;
                dir++;
            }
            else if(dir == 2) {
                for(int i = top; i <= down; i++) {
                    result[i][right] = num++;
                }
                right--;
                dir++;
            }
            else if(dir == 3) {
                for(int i = right; i >= left; i--) {
                    result[down][i] = num++;
                }
                down--;
                dir++;
            }
            else {
                for(int i = down; i >= top; i--) {
                    result[i][left] = num++;
                }
                left++;
                dir = 1;
            }
        }
        return result;
    }
};