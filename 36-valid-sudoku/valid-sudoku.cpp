class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<unordered_set<char>>> boxSet(9, vector<unordered_set<char>>(9));
        vector<unordered_set<char>> rowSet(9), colSet(9);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                if(boxSet[i / 3][j / 3].find(board[i][j]) != boxSet[i / 3][j / 3].end()) {
                    return false;
                }
                if(rowSet[i].find(board[i][j]) != rowSet[i].end()) {
                    return false;
                }
                if(colSet[j].find(board[i][j]) != colSet[j].end()) {
                    return false;
                }
                boxSet[i / 3][j / 3].insert(board[i][j]);
                rowSet[i].insert(board[i][j]);
                colSet[j].insert(board[i][j]);
            }
        }
        return true;
    }
};