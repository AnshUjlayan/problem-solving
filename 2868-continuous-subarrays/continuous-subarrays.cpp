class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long long result = 0;
        int l = 0, r = 0, n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        priority_queue<pair<int,int>> maxHeap;
        while (r < n) {
            minHeap.push({nums[r], r});
            maxHeap.push({nums[r], r});
            while (maxHeap.top().first - minHeap.top().first > 2) {
                result += r - l++;
                while (minHeap.top().second < l) {
                    minHeap.pop();
                }
                while (maxHeap.top().second < l) {
                    maxHeap.pop();
                }
            }
            r++;
        }
        result += 1ll * (r - l) * (r - l + 1) / 2;
        return result;
    }
};