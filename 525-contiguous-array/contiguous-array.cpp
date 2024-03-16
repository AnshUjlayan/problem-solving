class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0, sum = 0, n = nums.size();
        unordered_map<int,int> mp {{0, -1}};
        for(int i = 0; i < n; i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if(mp.find(sum) != mp.end()) {
                result = max(result, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }
        return result;
    }
};