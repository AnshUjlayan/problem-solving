class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(), arr.end());
        return accumulate(arr.begin() + left - 1, arr.begin() + right, static_cast<long long>(0)) % static_cast<int>(1e9 + 7);
    }
};