class Solution {
private:
    bool getSlimy(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = nums[0], r = nums[n - 1];
        int diff = (r - l) / (n - 1);
        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> result(m);
        for(int i = 0; i < m; i++) {
            result[i] = getSlimy(vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1));
        }
        return result;
    }
};