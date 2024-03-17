class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int prevL = intervals[0][0];
        int prevR = intervals[0][1];
        for(auto& interval : intervals) {
            int l = interval[0];
            int r = interval[1];
            if(l <= prevR) {
                prevR = max(prevR, r);
            }
            else {
                result.push_back({prevL, prevR});
                prevL = l;
                prevR = r;
            }
        }
        result.push_back({prevL, prevR});
        return result;
    }
};