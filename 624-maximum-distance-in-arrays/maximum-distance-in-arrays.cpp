class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int result = 0;
        int globalMin = 1e9, globalMax = -1e9;
        int mn = 1e9, mx = -1e9;
        for (auto& arr : arrays) {
            mn = *min_element(arr.begin(), arr.end());
            mx = *max_element(arr.begin(), arr.end());
            result = max({result, globalMax - mn, mx - globalMin});
            globalMin = min(globalMin, mn);
            globalMax = max(globalMax, mx);
        }
        return result;
    }
};