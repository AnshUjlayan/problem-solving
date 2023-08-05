class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        int result = 0, sum = 0;
        for(auto num : nums) {
            ump[sum]++;
            sum += num;
            if(ump.find(sum - k) != ump.end()) {
                result += ump[sum - k];
            }
        }
        return result;
    }
};