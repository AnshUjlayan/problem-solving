class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2);
        unordered_set<int> n1, n2;
        for(int x : nums1) {
            n1.insert(x);
        }
        for(int x : nums2) {
            n2.insert(x);
        }
        for(int x : n1) {
            if(n2.find(x) == n2.end()) {
                result[0].push_back(x);
            }
        }
        for(int x : n2) {
            if(n1.find(x) == n1.end()) {
                result[1].push_back(x);
            }
        }
        return result;
    }
};