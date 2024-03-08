class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        for(int& num : nums) {
            mp[num]++;
        }
        int res = 0, mx = 0;
        for(auto& [key, val]: mp) {
            mx = max(mx, val);
        }
        for(auto& [key, val]: mp) {
            res += mx == val ? val : 0;
        }
        return res;
    }
};