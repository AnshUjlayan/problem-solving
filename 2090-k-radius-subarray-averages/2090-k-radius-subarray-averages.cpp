class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        vector<int> result(n, -1);
        long long sum = 0;
        while(r < n) {
            int mid = l + ((r - l) / 2);
            sum += nums[r];
            if((r - l) == (2 * k)) {
                result[mid] = sum / (r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return result;
    }
};