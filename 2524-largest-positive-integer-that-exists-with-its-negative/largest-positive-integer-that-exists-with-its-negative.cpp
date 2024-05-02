class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
        unordered_set<int> ust;
        for(int& num : nums) {
            if(ust.count(-num)) {
                result = max(result, abs(num));
            }
            ust.insert(num);
        } 
        return result;
    }
};