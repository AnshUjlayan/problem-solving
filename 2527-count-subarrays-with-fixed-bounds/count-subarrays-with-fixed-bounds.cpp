class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> invalid, lower, upper;
        int n = nums.size(), inv = -1, mini = -1, maxi = -1;
        long long result = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                inv = i;
            }
            if(nums[i] == minK) {
                mini = i;
            }
            if(nums[i] == maxK) {
                maxi = i;
            }
            invalid.push_back(inv);
            lower.push_back(mini);
            upper.push_back(maxi);
        }
        for(int i = 0; i < n; i++) {
            int out = invalid[i];
            int left = min(lower[i], upper[i]);
            if(out < left) {
                result += left - out;
            }
        }
        return result;
    }
};