class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size(), result = 0;
        sort(points.begin(), points.end());
        for(int i = 0; i < n - 1; i++) {
            int dist = points[i + 1][0] - points[i][0];
            result = max(result, dist);
        }
        return result;
    }
};