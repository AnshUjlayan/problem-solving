class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        sort(shifts.begin(), shifts.end());
        int m = s.size(), n = shifts.size();
        int rotations = 0, ptr = 0;
        auto shift = [&](int idx) {
            rotations %= 26;
            int moves = (s[idx] - 'a' + rotations) % 26;
            moves += moves < 0 ? 26 : 0;
            s[idx] = moves + 'a';
        };
        for(int i = 0; i < m; i++) {
            while(ptr < n && shifts[ptr][0] == i) {
                int dir = shifts[ptr][2] == 0 ? -1 : 1;
                pq.push({shifts[ptr][1], dir});
                rotations += dir;
                ptr++;
            }
            shift(i);
            while(!pq.empty() && pq.top().first == i) {
                rotations -= pq.top().second;
                pq.pop();
            }
        }
        return s;
    }
};