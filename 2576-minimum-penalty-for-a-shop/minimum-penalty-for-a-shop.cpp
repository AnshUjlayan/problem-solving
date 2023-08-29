class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), nCount = 0, yCount = 0;
        vector<int> prefixSum(n + 1), postfixSum(n + 1);
        for(int i = 1; i <= n; i++) {
            if(customers[i - 1] == 'N') {
                nCount++;
            }
            prefixSum[i] = nCount;
        }
        for(int i = n - 1; i >= 0; i--) {
            if(customers[i] == 'Y') {
                yCount++;
            }
            postfixSum[i] = yCount;
        }
        int result = 0, penalty = INT_MAX;
        for(int i = 0; i <= n; i++) {
            int currPenalty = prefixSum[i] + postfixSum[i];
            if(currPenalty < penalty) {
                penalty = currPenalty;
                result = i;
            }
        }
        return result;
    }
};