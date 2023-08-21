class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        double result = 0.0;
        int total = m + n, l = 0, r = m;
        while(l <= r) {
            int idx1 = l + (r - l) / 2;
            int idx2 = (total + 1) / 2 - idx1;

            int curr1 = idx1 > 0 ? nums1[idx1 - 1] : INT_MIN;
            int next1 = idx1 < m ? nums1[idx1] : INT_MAX;
            int curr2 = idx2 > 0 ? nums2[idx2 - 1] : INT_MIN;
            int next2 = idx2 < n ? nums2[idx2] : INT_MAX;

            if(curr1 <= next2 && curr2 <= next1) {
                if(total & 1) {
                    result = max(curr1, curr2);
                }
                else {
                    result = (max(curr1, curr2) + min(next1, next2)) / 2.0;
                }
                break;
            }
            else if(curr1 > curr2) {
                r = idx1 - 1;
            }
            else {
                l = idx1 + 1;
            }
        }
        return result;
    }
};