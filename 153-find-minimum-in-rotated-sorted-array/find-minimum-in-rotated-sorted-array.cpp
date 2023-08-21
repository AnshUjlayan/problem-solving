class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = INT_MAX;
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            if(nums[l] < nums[r]) {
                result = min(result, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;
            result = min(result, nums[mid]);
            if(nums[mid] >= nums[l]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return result;
    }
};