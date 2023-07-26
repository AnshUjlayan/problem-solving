class Solution {
private:
    bool check(vector<int>& dist, double hour, int speed) {
        double currHr = 0.0;
        for(int i = 0; i < dist.size(); i++) {
            double complete = (double)dist[i] / (double)speed;
            currHr += (i == dist.size() - 1 ? complete : ceil(complete));
        }
        return currHr <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int result = -1;
        int maxSpeed = 1e7;
        int minSpeed = 1;
        while(maxSpeed >= minSpeed) {
            int mid = minSpeed + (maxSpeed - minSpeed) / 2;
            if(check(dist, hour, mid)) {
                maxSpeed = mid - 1;
                result = mid;
            }
            else {
                minSpeed = mid + 1;
            }
        }
        return result;
    }
};