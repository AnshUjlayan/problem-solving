class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int tot = mean * (rolls.size() + n) - accumulate(rolls.begin(), rolls.end(), 0);
        int rem = tot % n;
        if (tot < n || tot > n * 6)
            return {};
        vector<int> result(n, tot / n);
        while (rem)
            result[rem--]++;
        return result;
    }
};