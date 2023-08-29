class Solution {
private:
    bool canPut(vector<string>& subset, int n, int x, int y) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == x && j == y) {
                    continue;
                }
                if(x - i == y - j || x - i == -(y - j) || j == y) {
                    if(subset[i][j] == 'Q') {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void func(int& result, vector<string>& subset, int n, int i) {
        if(i == n) {
            result++;
            return;
        }
        for(int j = 0; j < n; j++) {
            if(canPut(subset, n, i, j)) {
                subset[i][j] = 'Q';
                func(result, subset, n, i + 1);
                subset[i][j] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<string> subset(n, string(n, '.'));
        func(result, subset, n, 0);
        return result;
    }
};