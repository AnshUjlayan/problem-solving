class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 1;
        vector<int> result(n);
        for(int& num : nums) {
            if(num < 0) {
                result[j] = num;
                j += 2;
                continue;
            }
            result[i] = num;
            i += 2;
        }
        return result;
    }
};