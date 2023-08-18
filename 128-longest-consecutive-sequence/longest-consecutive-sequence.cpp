class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_set<int> ust = unordered_set<int>(nums.begin(), nums.end());
        for(int num : nums) {
            if(ust.find(num - 1) == ust.end()) {
                int curr = num, res = 1;
                while(ust.find(curr + 1) != ust.end()) {
                    curr++;
                    res++;
                }
                result = max(result, res);
            }
        }
        return result;
    }
};