class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(happiness.rbegin(), happiness.rend());
        int n = happiness.size();
        long long result = 0;
        for(int i = 0; i < k && i < n; i++) {
            result += max(0, happiness[i] - i);
        }
        return result;
    }
};