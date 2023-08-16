class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, l = 0, r = 1;
        while(r < prices.size()) {
            if(prices[r] - prices[l] <= 0) {
                l = r;
            }
            else {
                result = max(result, prices[r] - prices[l]);
            }
            r++;
        }
        return result;
    }
};