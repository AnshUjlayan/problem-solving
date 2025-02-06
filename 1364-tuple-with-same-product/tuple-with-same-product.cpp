class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size(), res = 0;
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        for (auto &[k, v] : mp) {
            res += v * (v - 1);
        }
        return res * 4;
    }
};