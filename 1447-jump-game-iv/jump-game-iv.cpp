class Solution {
  public:
    int minJumps(vector<int>& arr) {
      unordered_map<int,vector<int>> adj;
      for(int i = 0; i < arr.size(); i++) {
        adj[arr[i]].push_back(i);
      }
      vector<bool> visited(arr.size(), false);
      queue<pair<int,int>> q;
      q.push({0, 0});
      visited[0] = true;
      while(!q.empty()) {
        auto [idx, cost] = q.front();
        q.pop();
        if(idx == arr.size() - 1) {
          return cost;
        }
        vector<int>& toJump = adj[arr[idx]];
        toJump.push_back(idx + 1);
        toJump.push_back(idx - 1);
        for(int& newIdx : toJump) {
          if(newIdx >= 0 && !visited[newIdx]) {
            visited[newIdx] = true;
            q.push({newIdx, cost + 1});
          }
        }
        toJump.clear();
      }
      throw;
    }
};