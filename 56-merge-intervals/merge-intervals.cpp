class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int l = intervals[0][0], r = intervals[0][1];
        for(auto& interval : intervals) {
            if(interval[0] > r) {
                result.push_back({l, r});
                l = interval[0];
            }
            r = max(interval[1], r);
        }
        result.push_back({l, r});
        return result;
    }
};