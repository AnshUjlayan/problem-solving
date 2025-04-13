class Solution {
public:
    int countPairs(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        long long res = 0, res2 = 0;
        const int MOD = 1e9 + 7;

        vector<int> powers;
        for (int i = 0; i < 22; i++) {
            powers.push_back(1 << i);
        }

        map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }

        for (auto& [k, v] : mp) {
            for (int& pow : powers) {
                if (mp.find(pow - k) != mp.end()) {
                    if (k + k == pow) {
                        res2 += 1ll * v * (v - 1) / 2;
                        res2 %= MOD;
                        continue;
                    }
                    res += 1ll * v * mp[pow - k];
                    res %= MOD;
                }
            }
        }

        return static_cast<int>(res) / 2 + static_cast<int>(res2);
    }
};