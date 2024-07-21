class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& edges, int k) {
        vector<vector<int>> adj(k + 1);
        vector<int> deg(k + 1), res;
        queue<int> q;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            deg[edge[1]]++;
        }
        for (int i = 1; i <= k; i++) {
            if (!deg[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            res.push_back(num);
            for (int& neighbour : adj[num]) {
                if (--deg[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        return res.size() == k ? res : vector<int>();
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> result(k, vector<int>(k, 0));
        vector<int> topoSortRow = topoSort(rowConditions, k);
        vector<int> topoSortCol = topoSort(colConditions, k);
        if (topoSortRow.empty() || topoSortCol.empty()) {
            return {};
        }
        vector<int> row(k + 1), col(k + 1);
        for (int i = 0; i < k; i++) {
            row[topoSortRow[i]] = i;
            col[topoSortCol[i]] = i;
        }
        for (int i = 1; i <= k; i++) {
            result[row[i]][col[i]] = i;
        }
        return result;
    }
};