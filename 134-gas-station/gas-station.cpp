class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, currIdx = 0, tank = 0;
        for(int i = 0; i < n; i++) {
            totalGas += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0) {
                tank = 0;
                currIdx = i + 1;
            }
        }
        return totalGas < 0 ? -1 : currIdx;
    }
};