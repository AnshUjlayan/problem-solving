class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());
        set_intersection(st1.begin(), st1.end(), st2.begin(), st2.end(), back_inserter(result));
        return result;
    }
};