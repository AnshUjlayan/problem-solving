class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = timePoints.size(), result = INT_MAX;
        vector<pair<int,int>> time;
        for (string& t : timePoints) {
            time.push_back({stoi(t.substr(0, 2)), stoi(t.substr(3, 2))});
        }
        sort(time.begin(), time.end(), [](pair<int,int> a, pair<int,int> b) {
            return a.first == b.first? a.second < b.second : a.first < b.first;
        });
        time.push_back({24 + time[0].first, time[0].second});
        for (int i = 1; i <= n; i++) {
            result = min(result, (time[i].first - time[i - 1].first) * 60 + (time[i].second - time[i - 1].second));
        }
        return result;
    }
};