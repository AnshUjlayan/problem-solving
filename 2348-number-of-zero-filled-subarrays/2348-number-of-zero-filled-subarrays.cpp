class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        int subArr = 0;
        for (auto num : nums) {
            if (num == 0)
                subArr++;
            else
                subArr = 0;
            result += subArr;
        }
        return result;
    }
};