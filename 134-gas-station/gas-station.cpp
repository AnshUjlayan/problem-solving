class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> track(n);
        for(int i = 0; i < n; i++) {
            track[i] = gas[i] - cost[i];
        }
        int currIdx = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            sum += track[i];
            if(sum < 0) {
                sum = 0;
                currIdx = i + 1;
            }
        }
        return currIdx == n || accumulate(track.begin(), track.end(), 0) < 0 ? -1 : currIdx;
    }
};