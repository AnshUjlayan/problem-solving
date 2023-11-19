class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0;
        while(++i < n) {
            if(nums[i] != nums[i - 1]) {
                break;
            }
        }
        int prev = nums[i - 1], count = 0, result = 0;
        while(i < n) {
            if(nums[i] != prev) {
                prev = nums[i];
                count++;
            }
            result += count;
            i++;
        }
        return result;
    }
};