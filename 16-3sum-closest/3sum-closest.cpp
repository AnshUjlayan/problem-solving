class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), result = INT_MAX, dist = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int selected = nums[i];
            int l = i + 1, r = n - 1;
            while(l < r) {
                int currSum = selected + nums[l] + nums[r];
                if(abs(target - currSum) < dist) {
                    dist = abs(target - currSum);
                    result = currSum;
                }
                if(currSum < target) {
                    l++;
                    while(l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
                else {
                    r--;
                }
            }
        }
        return result;
    }
};