class Solution {
private:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sortedArr;
        int l1 = 0, r1 = nums1.size();
        int l2 = 0, r2 = nums2.size();
        
        while (l1 < r1 && l2 < r2) {
            if (nums1[l1] < nums2[l2]) {
                sortedArr.push_back(nums1[l1++]);
            } else {
                sortedArr.push_back(nums2[l2++]);
            }
        }
        
        while (l1 < r1) {
            sortedArr.push_back(nums1[l1++]);
        }
        
        while (l2 < r2) {
            sortedArr.push_back(nums2[l2++]);
        }
        
        return sortedArr;
    }

    vector<int> mergeSort(vector<int>& nums, int l, int r) {
        if (l == r) {
            return {nums[l]};
        }
        if (l > r) {
            return {};
        }
        
        int mid = l + (r - l) / 2;
        
        vector<int> leftSorted = mergeSort(nums, l, mid);
        vector<int> rightSorted = mergeSort(nums, mid + 1, r);
        
        return merge(leftSorted, rightSorted);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        if (nums.empty()) {
            return {};
        }
        
        return mergeSort(nums, 0, nums.size() - 1);
    }
};