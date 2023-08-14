class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = cost[n - 1], b = 0;
        for(int i = n - 2; i >= 0; i--) {
            int temp = cost[i] + min(a, b);
            b = a;
            a = temp;
        }
        return min(a, b);
    }
};