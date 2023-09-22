class Solution {
  public:
    int maxSubarraySumCircular(vector<int>& nums) {
      int total = 0, currMax = INT_MIN, currMin = INT_MAX, sumMax = 0, sumMin = 0;
      for(int& num : nums) {
        sumMax += num;
        sumMin += num;
        currMax = max(currMax, sumMax);
        currMin = min(currMin, sumMin);
        sumMax = sumMax < 0 ? 0 : sumMax;
        sumMin = sumMin > 0 ? 0 : sumMin;
        total += num;
      }
      return currMin == total ? currMax : max(currMax, total - currMin);
    }
};