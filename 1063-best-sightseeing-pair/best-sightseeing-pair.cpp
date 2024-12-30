class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int result = 0, x = 0, mx = 0;
        for(int &val : values) {
            result = max(result, mx - x + val);
            mx = max(mx, val + x++);
        }
        return result;
    }
};