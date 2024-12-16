class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto comp = [&](int i, int j) {
            return nums[i] == nums[j] ? i > j : nums[i] > nums[j];
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (int i = 0; i < nums.size(); i++) {
            pq.push(i);
        }
        while (k--) {
            int top = pq.top();
            pq.pop();
            nums[top] *= multiplier;
            pq.push(top);
        }
        return nums;
    }
};