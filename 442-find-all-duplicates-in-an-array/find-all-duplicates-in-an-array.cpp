class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> result;
        for(int& num : nums) {
            nums[abs(num) - 1] *= -1;
            if(nums[abs(num) - 1] > 0) {
                result.push_back(abs(num));
            }
        }
        return result;
    }
};