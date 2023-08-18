class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        int picked;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            picked = nums[i];
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(picked + nums[l] + nums[r] == 0) {
                    vector<int> temp = {picked, nums[l], nums[r]};
                    result.insert(temp);
                    l++;
                    while(l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
                else if(picked + nums[l] + nums[r] < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};