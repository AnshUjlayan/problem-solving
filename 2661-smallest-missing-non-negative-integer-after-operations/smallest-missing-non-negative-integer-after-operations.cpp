class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mp(value + 1, 0);
        for (int n : nums) {
            mp[((n % value) + value) % value]++;
        }
        int res = 0;
        while (--mp[res % value] >= 0) {
            res++;
        }
        return res;
    }
};