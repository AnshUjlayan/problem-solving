class Solution {
private:
    unordered_map<int,int> ump;

    int getSlimy(vector<int>& nums, int k, int idx) {
        if (idx == nums.size()) {
            return 1;
        }
        int res = getSlimy(nums, k, idx + 1);
        if (!ump[nums[idx] - k] && !ump[nums[idx] + k]) {
            ump[nums[idx]]++;
            res += getSlimy(nums, k, idx + 1);
            ump[nums[idx]]--;
        }
        return res;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        return getSlimy(nums, k, 0) - 1;
    }
};
