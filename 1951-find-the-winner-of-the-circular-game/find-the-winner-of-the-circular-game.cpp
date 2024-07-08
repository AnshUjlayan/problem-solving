class Solution {
public:
    int findTheWinner(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> nums;
        int idx = 0;
        for(int i = 0; i < n; i++) {
            nums.push_back(i);
        }
        while(nums.size() > 1) {
            idx = (idx + k - 1) % nums.size();
            nums.erase(nums.begin() + idx);
        }
        return nums[0] + 1;
    }
};