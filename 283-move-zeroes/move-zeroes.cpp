class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        while(i < n && j < n) {
            while(j < n && nums[j] != 0) {
                j++;
            }
            if(i > j && nums[i] != 0) {
                swap(nums[i], nums[j]);
            }
            i++;
        }
    }
};