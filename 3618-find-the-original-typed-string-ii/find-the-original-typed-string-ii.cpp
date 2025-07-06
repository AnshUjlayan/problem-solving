class Solution {
public:
    int possibleStringCount(string word, int k) {
        // because im a sweat
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        const int MOD = 1e9 + 7;
        long long res = 1, cnt = 1;

        // build freq array
        vector<int> arr;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] != word[i - 1]) {
                res = (res * cnt) % MOD;
                arr.push_back(cnt);
                cnt = 0;
            }
            cnt++;
        }
        arr.push_back(cnt);
        res = (res * cnt) % MOD;

        // initialise dp vectors
        vector<int> dp(k, 0), nextDp(k, 0);
        fill(dp.begin() + max(0, k - arr[0] - 1), dp.end(), 1);
        k -= 2;

        // main logic
        for (int i = 1; i < arr.size(); i++) {
            if (k < 0) break;
            for (int j = k; j >= 0; j--) {
                dp[j] = (dp[j] + dp[j + 1]) % MOD;
                nextDp[j] = (0ll + dp[j + 1] - dp[min(j + arr[i] + 1, k + 1)] + MOD) % MOD;
            }
            swap(dp, nextDp);
            fill(nextDp.begin(), nextDp.begin() + max(0, k--), 0);
        }

        return ((res - accumulate(dp.begin(), dp.begin() + max(0, k + 1), 0ll) % MOD) + MOD) % MOD;
    }
};