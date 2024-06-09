class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<int,int> mp {{0, 1}};
        int sum = 0, result = 0;
        for(int& num : nums) {
            sum = (((sum + num) % k) + k) % k;
            result += mp[sum]++;
        }
        return result;
    }
};