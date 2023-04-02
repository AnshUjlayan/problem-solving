class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        sort(potions.begin(), potions.end());
        int m = potions.size();
        for(int spell : spells) {
            long long calc = ceil((1.0 * success) / spell);
            auto idx = lower_bound(potions.begin(), potions.end(), calc) - potions.begin();
            result.push_back(m - idx);
        }
        return result;
    }
};