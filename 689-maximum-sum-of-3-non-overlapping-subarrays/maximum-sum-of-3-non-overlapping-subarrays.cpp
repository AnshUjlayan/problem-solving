class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> result(3, 0);
        int n = nums.size();
        vector<pair<int,int>> left(n), right(n);
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int l = 0, r = k, mx = sum, mark = 0;
        while (r < n) {
            left[r] = {mx, mark};
            sum += nums[r++] - nums[l++];
            if (sum > mx) {
                mx = sum;
                mark = l;
            }
        }
        sum = accumulate(nums.begin() + n - k, nums.end(), 0);
        l = n - k - 1, r = n - 1, mx = sum, mark = n - k;
        while (l >= 0) {
            right[l] = {mx, mark};
            sum += nums[l] - nums[r--];
            if (sum >= mx) {
                mx = sum;
                mark = l;
            }
            l--;
        }
        sum = accumulate(nums.begin() + k, nums.begin() + k + k, 0);
        l = k, r = k + k, mx = 0;
        while (r < n - k + 1) {
            if (sum + left[l].first + right[r - 1].first > mx) {
                mx = sum + left[l].first + right[r - 1].first;
                result = {left[l].second, l, right[r - 1].second};
            }
            sum += nums[r++] - nums[l++];
        }
        return result;
    }
};