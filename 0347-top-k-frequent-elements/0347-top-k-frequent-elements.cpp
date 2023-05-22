class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> ump;
        for(int num : nums) {
            ump[num]++;
        }
        multimap<int, int, greater<int>> mp;
        for(auto& x : ump) {
            mp.insert({x.second, x.first});
        }
        int i = 0;
        for(auto& x : mp) {
            if(i >= k) {
                break;
            }
            result.push_back(x.second);
            i++;
        }
        return result;
    }
};