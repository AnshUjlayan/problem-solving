class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = startTime.size(), res = 0;
        vector<int> arr(n + 1);
        arr[0] = startTime[0];
        for (int i = 1; i < n; i++) {
            arr[i] = startTime[i] - endTime[i - 1] + arr[i - 1];
            res = max(res, arr[i] - (i - k - 1 < 0 ? 0 : arr[i - k - 1]));
        }
        arr[n] = eventTime - endTime[n - 1] + arr[n - 1];
        res = max(res, arr[n] - (n - k - 1 < 0 ? 0 : arr[n - k - 1]));
        return res;
    }
};