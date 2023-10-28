class Solution {
public:
    int countVowelPermutation(int n) {
       vector<vector<int>> adj {{1, 2, 3, 4, 5}, {2}, {1, 3}, {1, 2, 4, 5}, {3, 5}, {1}};
       vector<int> dp(6, 0);
       dp[0] = 1;
       for(int i = 0; i < n; i++) {
           vector<int> nextDp(6, 0);
           for(int j = 0; j < 6; j++) {
               for(int& vowel : adj[j]) {
                   nextDp[vowel] = ((long long)nextDp[vowel] + dp[j]) % (int)(1e9 + 7);
               }
           }
           dp = nextDp;
       }
       return (int)(accumulate(dp.begin(), dp.end(), (long long)0) % (int)(1e9 + 7));
    }
};