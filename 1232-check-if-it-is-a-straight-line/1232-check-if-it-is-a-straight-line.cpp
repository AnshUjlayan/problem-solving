class Solution {
private:
    double getSlope(vector<vector<int>>& coordinates, int i, int j) {
        if(coordinates[i][0] < coordinates[j][0]) {
            swap(i, j);
        }
        int x1 = coordinates[i][0];
        int y1 = coordinates[i][1];
        int x2 = coordinates[j][0];
        int y2 = coordinates[j][1];
        return (double)(x2 - x1) / (y2 - y1);
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope = getSlope(coordinates, 0, 1);
        for(int i = 2; i < coordinates.size(); i++) {
            if(slope != getSlope(coordinates, 0, i)) {
                return false;
            }
        }
        return true;
    }
};