class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(mid < nums.size() - 1 && nums[mid + 1] >= nums[mid])
                low = mid + 1;
            else if(mid > 0 && nums[mid - 1] >= nums[mid])
                high = mid - 1;
            else
                return mid;
        }
        return high;
    }
};