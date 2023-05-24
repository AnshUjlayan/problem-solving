class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long result = 0, totalSum = 0;
        vector<pair<int, int>> nums(nums1.size());
        for (int i = 0; i < nums.size(); i++) {
            nums[i].first = nums2[i];
            nums[i].second = nums1[i];
        }
        sort(nums.begin(), nums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums) {
            pq.push(num.second);
            totalSum += num.second;
            if (pq.size() > k) {
                totalSum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                result = max(result, totalSum * num.first);
            }
        }
        return result;
    }
};