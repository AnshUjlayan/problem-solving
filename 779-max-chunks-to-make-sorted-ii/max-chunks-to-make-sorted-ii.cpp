class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        arr.push_back(1e9);
        int res = 0, n = arr.size(), temp = 1e9;
        vector<int> right(n);
        for (int i = n - 1; i >= 0; i--) {
            temp = min(temp, arr[i]);
            right[i] = temp;
        }
        temp = arr[0];
        for (int i = 1; i < n; i++) {
            res += temp <= right[i];
            temp = max(temp, arr[i]);
        }
        return res;
    }
};