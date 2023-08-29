class Solution {
private:
    vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool boundsCheck(vector<vector<char>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int idx, int i, int j) {
        if(board[i][j] == word[idx]) {
            idx++;
            if(idx == word.size()) {
                return true;
            }
        }
        else {
            return false;
        }
        bool result = false;
        for(auto& direction : directions) {
            int x = i + direction[0], y = j + direction[1];
            if(boundsCheck(board, x, y) && !visited[x][y]) {
                visited[x][y] = true;
                result = result || dfs(board, visited, word, idx, x, y);
                visited[x][y] = false;
            }
        }
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = true;
                if(dfs(board, visited, word, 0, i, j)) {
                    return true;
                }
                visited[i][j] = false;
            }
        }
        return false;
    }
};