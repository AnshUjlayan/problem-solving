class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = startTime.size(), res = 0, mx = 0;
        vector<int> arr(n + 1), right(n);
        arr[0] = startTime[0];
        for (int i = 1; i < n; i++) {
            arr[i] = startTime[i] - endTime[i - 1];
        }
        arr[n] = eventTime - endTime[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = mx = max(mx, arr[i + 2]);
        }
        mx = 0;
        for (int i = 0; i < n; i++) {
            int sz = endTime[i] - startTime[i];
            if (sz <= mx || sz <= right[i]) {
                res = max(res, arr[i] + arr[i + 1] + sz);
            } else {
                res = max(res, arr[i] + arr[i + 1]);
            }
            mx = max(mx, arr[i]);
        }
        return res;
    }
};