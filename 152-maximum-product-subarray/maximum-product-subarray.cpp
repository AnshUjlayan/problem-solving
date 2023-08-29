class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN, currMin = 1, currMax = 1;
        for(int num : nums) {
            int temp = currMax * num;
            currMax = max({num, temp, currMin * num});
            currMin = min({num, temp, currMin * num});
            result = max(result, currMax);
        }
        return result;
    }
};