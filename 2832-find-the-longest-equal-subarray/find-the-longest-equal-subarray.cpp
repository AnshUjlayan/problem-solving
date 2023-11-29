class Solution {
private:
    int getSlimy(vector<int>& nums, int k) {
        int n = nums.size(), result = 0, l = 0, r = 0;
        while(r < n) {
            while((nums[r] - nums[l]) - (r - l) > k) {
                l++;
            }
            result = max(result, ++r - l);
        }
        return result;
    }
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> ump;
        int n = nums.size(), result = 0;
        for(int i = 0; i < n; i++) {
            ump[nums[i]].push_back(i);
        }
        for(auto& [key, valArr] : ump) {
            result = max(result, getSlimy(valArr, k));
        }
        return result;
    }
};