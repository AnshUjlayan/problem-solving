class DSU {
  private:
    int groups;
    vector<int> parent, rank;
  public:
    DSU(int n) : parent(n), rank(n, 0) {
      this->groups = n;
      for(int i = 0; i < n; i++) {
        parent[i] = i;
      }
    }
    int getGroups() {
      return groups;
    }
    int find(int u) {
      if(parent[u] != u) {
        return parent[u] = find(parent[u]);
      }
      return u;
    }
    void join(int u, int v) {
      int pu = find(u), pv = find(v);
      if(pu == pv) {
        return;
      }
      groups--;
      if(rank[pu] > rank[pv]) {
        parent[pv] = pu;
      }
      else if(rank[pv] > rank[pu]) {
        parent[pu] = pv;
      }
      else {
        parent[pv] = pu;
        rank[pu]++;
      }
    }
};

class Solution {
  private:
    bool slimy(string a, string b) {
      int slime = 0;
      for(int i = 0; i < a.size(); i++) {
        slime += a[i] == b[i] ? 0 : 1;
      }
      return slime == 0 || slime == 2;
    }
  public:
    int numSimilarGroups(vector<string>& strs) {
      int n = strs.size();
      DSU dsu(n);
      for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
          if(slimy(strs[i], strs[j])) {
            dsu.join(i, j);
          }
        }
      }
      return dsu.getGroups();
    }
};