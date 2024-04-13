class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long long result = nums.size();
        stack<pair<int,int>> stk;
        for (int& num : nums) {
            while (!stk.empty() && stk.top().first < num) {
                stk.pop();
            }
            if(!stk.empty() && stk.top().first == num) {
                auto [element, freq] = stk.top();
                stk.pop();
                result += freq;
                stk.push({num, freq + 1});
            }
            else {
                stk.push({num, 1});
            }
        }
        return result;
    }
};