class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int result = 0;
        int l = intervals[0][0], r = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(r > intervals[i][0]) {
                result++;
                r = min(r, intervals[i][1]);
            }
            else {
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        return result;
    }
};