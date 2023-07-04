class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(int& num : nums) {
            if(ump[num] == 2)
                ump.erase(num);
            else
                ump[num]++;
        }
        for(auto& result : ump)
            return result.first;
        return -1;
    }
};