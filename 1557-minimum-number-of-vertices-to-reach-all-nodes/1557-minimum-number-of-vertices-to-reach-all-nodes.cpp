class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> result;
        vector<bool> degree(n, false);
        for(auto edge : edges) {
            degree[edge[1]] = true;
        }
        for(int i = 0; i < n; i++) {
            if(!degree[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};