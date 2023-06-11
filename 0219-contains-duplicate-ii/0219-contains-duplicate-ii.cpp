class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> ump;
        for(int i = 0; i < nums.size(); i++) {
            if(ump.find(nums[i]) != ump.end()) {
                for(auto x : ump[nums[i]])
                    if(abs(x - i) <= k)
                        return true;
            }
            ump[nums[i]].push_back(i);
        }
        return false;
    }
};