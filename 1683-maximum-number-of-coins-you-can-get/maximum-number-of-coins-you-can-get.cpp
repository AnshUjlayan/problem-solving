class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int result = 0, l = 0, r = piles.size() - 1;
        while(l < r) {
            result += piles[--r];
            l++, r--;
        }
        return result;
    }
};