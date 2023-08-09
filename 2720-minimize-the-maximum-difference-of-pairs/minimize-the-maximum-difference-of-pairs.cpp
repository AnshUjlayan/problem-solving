class Solution {
private:
    bool isValid(vector<int>& nums, int p, int num) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i + 1] - nums[i] <= num) {
                p--;
                i++;
            }
        }
        return p <= 0;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[nums.size() - 1] - nums[0];
        int result = r;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(isValid(nums, p, mid)) {
                result = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return result;
    }
};