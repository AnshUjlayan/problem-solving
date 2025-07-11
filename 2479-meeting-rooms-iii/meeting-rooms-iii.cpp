class Solution {
private:
    struct Meeting {
        long long start, end;
        int roomId;
        Meeting(long long start, long long end, int roomId) : start(start), end(end), roomId(roomId) {}
    };

public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        auto cmpUsed = [](Meeting* a, Meeting* b) { return a->end > b->end; };
        priority_queue<Meeting*, vector<Meeting*>, decltype(cmpUsed)> used(cmpUsed);
        priority_queue<int, vector<int>, greater<int>> avail;
        
        long long time = 0;
        int m = meetings.size(), res = 0;
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            avail.push(i);
        }

        for (int i = 0; i < m; i++) {
            if (avail.empty()) {
                time = max({time, used.top()->end, 0ll + meetings[i][0]});
            } else {
                time = max(time, 0ll + meetings[i][0]);
            }
            while (!used.empty() && used.top()->end <= time) {
                avail.push(used.top()->roomId);
                used.pop();
            }
            cnt[avail.top()]++;
            used.push(new Meeting(time, time + (meetings[i][1] - meetings[i][0]), avail.top()));
            avail.pop();
        }

        while (!used.empty()) {
            delete used.top();
            used.pop();
        }

        for (int i = 0; i < n; i++) {
            if (cnt[i] > cnt[res]) {
                res = i;
            }
        }

        return res;
    }
};