class Solution {
private:
    int MOD = 1e9 + 7;
    int getSlimy(unordered_map<int, int>& dp, unordered_map<int, vector<pair<int,int>>>& adj, int node) {
        if(dp.find(node) != dp.end()) {
            return dp[node];
        }
        long long result = 1;
        for(auto& [left, right] : adj[node]) {
            long long temp = (long long)1 * getSlimy(dp, adj, left) * getSlimy(dp, adj, right);
            result = (result + temp) % MOD;
        }
        return dp[node] = (int)result;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_set<int> ust(arr.begin(), arr.end());
        unordered_map<int, vector<pair<int,int>>> adj;
        unordered_map<int, int> dp;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < arr.size(); j++) {
                if((long long)arr[i] * arr[j] > 1e9) {
                    continue;
                }
                if(ust.find((long long)arr[i] * arr[j]) != ust.end()) {
                    adj[arr[i] * arr[j]].push_back({arr[i], arr[j]});
                }
            }
        }
        long long result = 0;
        for(int& node : arr) {
            result = (result + getSlimy(dp, adj, node)) % MOD;
        }
        return (int)result;
    }
};