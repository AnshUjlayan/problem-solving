class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        vector<string> result;
        while(r < n) {
            while(r + 1 < n && nums[r + 1] == nums[r] + 1) {
                r++;
            }
            string str = to_string(nums[l]) + "->" + to_string(nums[r]);
            l == r ? result.push_back(to_string(nums[l])) : result.push_back(str);
            r++;
            l = r;
        }
        return result;
    }
};