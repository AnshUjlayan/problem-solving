class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(events.begin(), events.end());
        int n = events.size(), result = 0;
        vector<int> mxr(n, 0);
        mxr[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            mxr[i] = max(mxr[i + 1], events[i][2]);
        }
        for (int i = 0; i < n; i++) {
            int temp = events[i][2];
            int next = lower_bound(events.begin() + i + 1, events.end(),
                                   vector<int>{events[i][1] + 1, 0, 0}) -
                       events.begin();
            if (next < n) {
                temp += mxr[next];
            }
            result = max(result, temp);
        }
        return result;
    }
};