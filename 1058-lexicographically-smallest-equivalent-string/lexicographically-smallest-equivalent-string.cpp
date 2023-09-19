class DSU {
  private:
    vector<int> parent;
  public:
    DSU() : parent(26) {
      for(int i = 0; i < 26; i++) {
        parent[i] = i;
      }
    }
    int find(int u) {
      if(parent[u] != u) {
        return parent[u] = find(parent[u]);
      }
      return parent[u];
    }
    void join(int u, int v) {
      int pu = find(u);
      int pv = find(v);
      if(pu == pv) {
        return;
      }
      if(pu < pv) {
        parent[pv] = pu;
      }
      else {
        parent[pu] = pv;
      }
    }
};

class Solution {
  public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
      DSU dsu;
      string result = "";
      for(int i = 0; i < s1.size(); i++) {
        dsu.join(s1[i] - 'a', s2[i] - 'a');
      }
      for(char& c : baseStr) {
        result += ('a' + dsu.find(c - 'a'));
      }
      return result;
    }
};