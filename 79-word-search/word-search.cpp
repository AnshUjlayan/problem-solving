class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int w) {
        if (w == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[w]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '@';
        bool result = dfs(board, word, i + 1, j, w + 1) ||
                      dfs(board, word, i - 1, j, w + 1) ||
                      dfs(board, word, i, j + 1, w + 1) ||
                      dfs(board, word, i, j - 1, w + 1);
        board[i][j] = temp;
        return result;
    }

public:
    bool exist(vector<vector<char>>& board, string& word) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};