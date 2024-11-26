class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        for (auto &edge : edges) {
            deg[edge[1]]++;
        }
        int winner = -1;
        for (int i = 0; i < n; i++) {
            if (!deg[i]) {
                if (winner != -1) {
                    return -1;
                }
                winner = i;
            }
        }
        return winner;
    }
};