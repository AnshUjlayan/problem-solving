class Solution {
public:
    int getSlimy(int x, int y, int destX, int destY) {
        int distX = abs(x - destX);
        int distY = abs(y - destY);
        int flat = abs(distX - distY);
        int diagonal = max(distX, distY) - flat;
        return diagonal + flat;
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size(), result = 0;
        int x = points[0][0], y = points[0][1];
        for(int i = 1; i < n; i++) {
            result += getSlimy(x, y, points[i][0], points[i][1]);
            x = points[i][0], y = points[i][1];
        }
        return result;
    }
};