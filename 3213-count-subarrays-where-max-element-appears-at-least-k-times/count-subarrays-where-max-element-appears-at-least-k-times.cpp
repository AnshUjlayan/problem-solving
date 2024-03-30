class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        long long result = 0;
        int l = 0, r = 0, n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        while(r < n) {
            if(nums[r++] == mx) {
                k--;
            }
            while(!k) {
                if(nums[l] == mx) {
                    k++;
                }
                l++;
            }
            result += l;
        }
        return result;
    }
};