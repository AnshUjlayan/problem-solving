class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result = 0, res = 0;
        for(int& num : nums) {
            res ^= num;
        }
        while(res || k) {
            result += (res & 1) ^ (k & 1);
            res >>= 1;
            k >>= 1;
        }
        return result;
    }
};