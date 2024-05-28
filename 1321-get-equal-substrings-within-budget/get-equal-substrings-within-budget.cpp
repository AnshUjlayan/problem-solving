class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = s.size();
        vector<int> arr(n);
        transform(s.begin(), s.end(), t.begin(), arr.begin(), [](char c1, char c2) { return abs(c1 - c2); });
        int result = 0, sumCost = 0, l = 0, r = 0;
        while (r < n) {
            sumCost += arr[r];
            ++r;
            while (sumCost > maxCost) {
                sumCost -= arr[l];
                ++l;
            }
            result = max(result, r - l);
        }
        return result;
    }
};