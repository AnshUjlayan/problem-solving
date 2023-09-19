class Solution {
  public:
    int minInsertions(string s) {
      int n = s.size();
      vector<int> dp(2, 0);
      for(int i = 0; i < n; i++) {
        vector<int> newDp(dp.size() + 1, 0);
        for(int j = i - 1; j >= 0; j--) {
          newDp[j] = 1 + min(newDp[j + 1], dp[j]);
          if(s[i] == s[j]) {
            newDp[j] = dp[j + 1];
          }
        }
        dp = newDp;
      }
      return dp[0];
    }
};