class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long long result = 0;
        vector<int> rd(n, 0);
        for (auto& road : roads) {
             rd[road[0]]++;
             rd[road[1]]++;
        }
        sort(rd.begin(), rd.end());
        for(int i = n; i > 0; i--) {
            result += 1ll * rd[i - 1] * i;
        }
        return result;
    }
};