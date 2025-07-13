class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = row.size(), res = 0;
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[row[i]] = i;
        }
        for (int i = 0; i < n; i += 2) {
            if (row[i] / 2 != row[i + 1] / 2) {
                int idx = mp[(row[i] / 2) * 2 + !(row[i] & 1)];
                mp[row[i + 1]] = idx;
                row[idx] = row[i + 1];
                res++;
            }
        }
        return res;
    }
};