class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> nums1(n, 0), nums2(n, 0);
        for(auto& t : trust) {
            nums1[t[1] - 1]++;
            nums2[t[0] - 1]++;
        }
        auto it1 = find(nums1.begin(), nums1.end(), n - 1) - nums1.begin() + 1;
        auto it2 = find(nums2.begin(), nums2.end(), 0) - nums2.begin() + 1;
        return it1 == it2 && it1 <= n ? it1 : -1;
    }
};