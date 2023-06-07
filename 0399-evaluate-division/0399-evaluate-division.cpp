class Solution {
private:
    double dfs(unordered_map<string,vector<pair<string,double>>>& adj, string curr, string end, double cost, set<string>& visited) {
        if(adj.find(curr) == adj.end() || visited.count(curr) > 0) {
            return DBL_MAX;
        }
        visited.insert(curr);
        if(curr == end) {
            return cost;
        }
        double res = DBL_MAX;
        for(auto x : adj[curr]) {
            string str = x.first;
            double cst = x.second;
            res = min(res, dfs(adj, str, end, cost * cst, visited));
        }
        return res;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size(), m = queries.size();
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i = 0; i < n; i++) {
            string uno = equations[i][0];
            string dos = equations[i][1];
            double y = values[i];
            adj[uno].push_back({dos, y});
            adj[dos].push_back({uno, 1.0 / y});
        }
        vector<double> result;
        set<string> visited;
        for(int i = 0; i < m; i++) {
            visited.clear();
            double x = dfs(adj, queries[i][0], queries[i][1], 1.0, visited);
            x = x == DBL_MAX ? -1.0 : x;
            result.push_back(x);
        }
        return result;
    }
};
