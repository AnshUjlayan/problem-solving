class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), result = 0, currDist = 0, currEnd = 0;
        for(int i = 0; i < n - 1; i++) {
            currDist = max(currDist, i + nums[i]);
            if(i == currEnd) {
                currEnd = currDist;
                result++;
            }
        }
        return result;
    }
};