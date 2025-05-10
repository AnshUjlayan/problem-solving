class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int f1 = count(nums1.begin(), nums1.end(), 0);
        int f2 = count(nums2.begin(), nums2.end(), 0);
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0ll) + f1;
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0ll) + f2;
        return (sum1 < sum2 && !f1) || (sum2 < sum1 && !f2) ? -1 : max(sum1, sum2);
    }
};