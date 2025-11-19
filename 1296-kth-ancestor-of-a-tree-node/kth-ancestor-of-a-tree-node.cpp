class TreeAncestor {
public:
    int LOG;
    vector<vector<int>> dp;

    TreeAncestor(int n, vector<int>& parent) {
        LOG = 1;
        while ((1 << LOG) < n) LOG++;
        dp.assign(n, vector<int>(LOG + 1, -1));
        for (int i = 0; i < n; i++) {
            dp[i][0] = parent[i];
        }
        for (int j = 1; j <= LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (dp[i][j - 1] == -1) continue;
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i <= LOG; i++) {
            if (k & (1 << i)) {
                node = dp[node][i];
                if (node == -1) break;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */