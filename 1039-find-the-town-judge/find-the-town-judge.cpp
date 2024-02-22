class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> nums(n, 0);
        for(auto& t : trust) {
            nums[t[0] - 1]--;
            nums[t[1] - 1]++;
        }
        auto it = find(nums.begin(), nums.end(), n - 1);
        return (it != nums.end()) ? (it - nums.begin() + 1) : -1;
    }
};