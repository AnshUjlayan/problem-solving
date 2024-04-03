class Solution {
private:
    int m, n;
    vector<vector<bool>> visited;
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int w) {
        if (w == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= this->m || j >= this->n || visited[i][j] ||
            board[i][j] != word[w]) {
            return false;
        }
        visited[i][j] = true;
        bool result = dfs(board, word, i + 1, j, w + 1) ||
                      dfs(board, word, i - 1, j, w + 1) ||
                      dfs(board, word, i, j + 1, w + 1) || 
                      dfs(board, word, i, j - 1, w + 1);
        visited[i][j] = false;
        return result;
    }

public:
    bool exist(vector<vector<char>>& board, string& word) {
        this->m = board.size();
        this->n = board[0].size();
        this->visited.resize(this->m, vector<bool>(this->n, false));
        for (int i = 0; i < this->m; i++) {
            for (int j = 0; j < this->n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};