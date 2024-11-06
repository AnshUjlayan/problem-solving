class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int i = 0, j = 0, cnt = 0, n = nums.size();
        while (i < n) {
            cnt = __builtin_popcount(nums[i]);
            j = i + 1;
            while (j < n && __builtin_popcount(nums[j]) == cnt) {
                j++;
            }
            sort(nums.begin() + i, nums.begin() + j);
            i = j;
        }
        for (auto num : nums) cout<<num<<" ";
        return is_sorted(nums.begin(), nums.end());
    }
};