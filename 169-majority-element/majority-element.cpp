class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(int& num : nums) {
            mp[num]++;
        }
        for(auto& [key, val] : mp) {
            if(val > nums.size() / 2) {
                return key;
            }
        }
        return -1;
    }
};