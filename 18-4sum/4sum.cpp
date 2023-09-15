class Solution {
  private:
    void func(set<vector<int>>& result, vector<int>& nums, int a, int b, long target, int l, int r) {
      while(l < r) {
        if(nums[l] + nums[r] < target) {
          l++;
        }
        else if(nums[l] + nums[r] > target) {
          r--;
        }
        else {
          result.insert({a, b, nums[l], nums[r]});
          l++;
          r--;
        }
      }
    }
  public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      set<vector<int>> result;
      int n = nums.size();
      for(int a = 0; a < n; a++) {
        if(a > 0 && nums[a] == nums[a - 1]) {
          continue;
        }
        for(int b = a + 1; b < n; b++) {
          if(b > a + 1 && nums[b] == nums[b - 1]) {
            continue;
          }
          func(result, nums, nums[a], nums[b], (long)target - nums[a] - nums[b], b + 1, n - 1);
        }
      }
      return vector<vector<int>>(result.begin(), result.end());
    }
};