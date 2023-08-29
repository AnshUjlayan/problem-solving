class Solution {
private:
    bool outOfBounds(vector<vector<char>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        return x < 0 || y < 0 || x >= m || y >= n;
    }

    bool dfs(vector<vector<char>>& board, string& word, int idx, int i, int j) {
        if(outOfBounds(board, i, j) || word[idx] != board[i][j]) {
            return false;
        }
        if(idx == word.size() - 1) {
            return true;
        }
        board[i][j] = '$';
        if(dfs(board, word, idx + 1, i + 1, j) || dfs(board, word, idx + 1, i - 1, j) || dfs(board, word, idx + 1, i, j + 1) || dfs(board, word, idx + 1, i, j - 1)) {
            return true;
        }
        board[i][j] = word[idx];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};