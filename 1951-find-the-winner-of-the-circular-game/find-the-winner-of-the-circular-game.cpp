class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> nums(n, false);
        int idx = 0, cnt = k, t = n - 1;
        while(t) {
            if (!nums[idx]) {
                if (!--cnt) {
                    cnt = k;
                    t--;
                    nums[idx] = true;
                }
            }
            idx = (idx + 1) % n;
        }
        return find(nums.begin(), nums.end(), false) - nums.begin() + 1;
    }
};