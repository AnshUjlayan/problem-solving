class Solution {
private:
    int func(vector<vector<int>>& dp, vector<vector<int>>& adj, int n, int vowel) {
        if(n <= 0) {
            return n == 0 ? 1 : 0;
        }
        if(dp[n][vowel] != -1) {
            return dp[n][vowel];
        }
        long long result = 0;
        for(int& nextVowel : adj[vowel]) {
            result += func(dp, adj, n - 1, nextVowel);
            result %= (int)(1e9 + 7);
        }
        return dp[n][vowel] = (int)result;
    }
public:
    int countVowelPermutation(int n) {
       vector<vector<int>> adj {{1, 2, 3, 4, 5}, {2}, {1, 3}, {1, 2, 4, 5}, {3, 5}, {1}};
       vector<vector<int>> dp(n + 1, vector<int>(6, -1));
       return func(dp, adj, n, 0);
    }
};