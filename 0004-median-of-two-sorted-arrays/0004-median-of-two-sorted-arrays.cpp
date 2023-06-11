class Solution {
private:
    double median(vector<int>& nums) {
        int len = nums.size();
        return len & 1 ? (double)nums[(len - 1) / 2] : (double)(nums[len / 2 - 1] + nums[len / 2]) / 2;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), ptr1 = 0, ptr2 = 0;
        vector<int> nums(m + n);
        while(ptr1 < m || ptr2 < n) {
            int num;
            if(ptr1 < m && ptr2 < n) {
                num = min(nums1[ptr1], nums2[ptr2]);
                num == nums1[ptr1] ? ptr1++ : ptr2++;
            }
            else
                num = ptr1 < m ? nums1[ptr1++] : nums2[ptr2++];
            nums[ptr1 + ptr2 - 1] = num;
        }
        return median(nums);
    }
};