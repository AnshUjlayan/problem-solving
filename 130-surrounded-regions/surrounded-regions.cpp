class Solution {
private:
    bool outOfBounds(vector<vector<char>>& board, int i, int j) {
        int m = board.size(), n = board[0].size();
        return i < 0 || j < 0 || i >= m || j >= n;
    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
        if(outOfBounds(board, i, j) || visited[i][j] || board[i][j] == 'X') {
            return;
        }
        visited[i][j] = true;
        board[i][j] = 'X';
        dfs(board, visited, i, j - 1);
        dfs(board, visited, i, j + 1);
        dfs(board, visited, i - 1, j);
        dfs(board, visited, i + 1, j);
    }
    void dfsZ(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
        if(outOfBounds(board, i, j) || visited[i][j] || board[i][j] == 'X') {
            return;
        }
        visited[i][j] = true;
        dfsZ(board, visited, i, j - 1);
        dfsZ(board, visited, i, j + 1);
        dfsZ(board, visited, i - 1, j);
        dfsZ(board, visited, i + 1, j);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if(board[i][j] == 'O') {
                        dfsZ(board, visited, i, j);
                    }
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    dfs(board, visited, i, j);
                }
            }
        }
    }
};