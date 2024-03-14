class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, result = 0;
        map<int,int> mp {{0, 1}};
        for(int & num : nums) {
            sum += num;
            result += mp[sum - goal];
            mp[sum]++;
        }
        return result;
    }
};