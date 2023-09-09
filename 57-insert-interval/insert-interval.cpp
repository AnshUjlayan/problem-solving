class Solution {
private:
    bool overlaps(int l, int r, int x, int y) {
        bool a = x >= l && x <= r;
        bool b = y >= l && y <= r;
        bool c = x >= l && y <= r;
        bool d = x <= l && y >= r;
        return a || b || c || d;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        for(int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            if(overlaps(l, r, newInterval[0], newInterval[1])) {
                newInterval[0] = min(l, newInterval[0]);
                newInterval[1] = max(r, newInterval[1]);
                continue;
            }
            if(newInterval[0] < l) {
                result.push_back({newInterval[0], newInterval[1]});
                newInterval[0] = 1e5 + 1;
            }
            result.push_back({l, r});
        }
        if(result.empty() || newInterval[0] != 1e5 + 1) {
            result.push_back({newInterval[0], newInterval[1]});
        }
        return result;
    }
};