class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for (int i = 0; i < prices.size(); i++) {
            int mn = 1e9;
            for (int j = i + 1; j < prices.size(); j++) {
                mn = min(mn, prices[j]);
                if (mn <= prices[i]) {
                    break;
                }
            }
            if (mn <= prices[i]) {
                prices[i] -= mn;
            }
        }
        return prices;
    }
};