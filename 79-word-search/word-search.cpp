class Solution {
private:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited,
             string& word, int i, int j, int w) {
        if (w == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            visited[i][j] || board[i][j] != word[w]) {
            return false;
        }
        visited[i][j] = true;
        bool result = dfs(board, visited, word, i + 1, j, w + 1) ||
                      dfs(board, visited, word, i - 1, j, w + 1) ||
                      dfs(board, visited, word, i, j + 1, w + 1) ||
                      dfs(board, visited, word, i, j - 1, w + 1);
        visited[i][j] = false;
        return result;
    }

public:
    bool exist(vector<vector<char>>& board, string& word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, visited, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};