class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (lower_bound(nums.begin(), nums.end(), i + 1) ==
                nums.begin() + n - i - 1) {
                return i + 1;
            }
        }
        return -1;
    }
};