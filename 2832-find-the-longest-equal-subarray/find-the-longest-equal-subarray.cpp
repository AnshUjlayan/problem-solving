class Solution {
private:
    int getSlimy(vector<int>& nums, int k) {
        int n = nums.size(), result = 0;
        deque<int> dq;
        for(int i = 0; i < n; i++) {
            dq.push_front(nums[i]);
            while(dq.front() - dq.back() - ((int)dq.size() - 1) > k) {
                dq.pop_back();
            }
            result = max(result, (int)dq.size());
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