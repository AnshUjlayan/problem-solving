class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        vector<int> arr(n, 1), result(n - k + 1, -1);
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                arr[i] += arr[i - 1];
            }
        }
        for (int i = 0; i < n - k + 1; i++) {
            if (arr[i + k - 1] >= k) {
                result[i] = nums[i + k - 1];
            }
        }
        return result;
    }
};