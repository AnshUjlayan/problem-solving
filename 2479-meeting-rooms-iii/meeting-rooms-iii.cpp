#define ll long long

class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> avail;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> used;
        
        long long time = 0;
        int m = meetings.size(), res = 0;
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            avail.push(i);
        }

        for (int i = 0; i < m; i++) {
            if (avail.empty()) {
                time = max({time, used.top().first, 0ll + meetings[i][0]});
            } else {
                time = max(time, 0ll + meetings[i][0]);
            }
            while (!used.empty() && used.top().first <= time) {
                avail.push(used.top().second);
                used.pop();
            }
            cnt[avail.top()]++;
            used.push({time + (meetings[i][1] - meetings[i][0]), avail.top()});
            avail.pop();
        }

        for (int i = 0; i < n; i++) {
            if (cnt[i] > cnt[res]) {
                res = i;
            }
        }

        return res;
    }
};