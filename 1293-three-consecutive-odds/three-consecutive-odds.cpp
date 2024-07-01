class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int x = 0;
        for (int& num : arr) {
            x = num & 1 ? x + 1 : 0;
            if (x == 3) {
                return true;
            }
        }
        return false;
    }
};