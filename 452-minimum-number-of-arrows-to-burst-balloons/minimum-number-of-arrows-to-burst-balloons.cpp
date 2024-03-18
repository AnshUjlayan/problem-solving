class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int result = 0, idx = 0, n = points.size();
        long long l = LONG_MIN, r = LONG_MIN;
        while(idx < n) {
            int currL = points[idx][0];
            int currR = points[idx][1];
            if(r >= currL) {
                l = (long long)max(l, (long long)currL);
                r = (long long)min(r, (long long)currR);
            }
            else {
                l = (long long)currL;
                r = (long long)currR;
                result++;
            }
            idx++;
        }
        return result;
    }
};