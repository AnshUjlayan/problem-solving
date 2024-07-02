class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
         unordered_map<int,int> mp;
        vector<int> result;
        for (int& x : nums1) {
            mp[x]++;
        }
        for (int& x : nums2) {
            if (mp[x]) {
                result.push_back(x);
                mp[x]--;
            }
        }
        return result;
    }
};