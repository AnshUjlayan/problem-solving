class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        priority_queue<pair<int,int>> maxHeap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        int n = nums.size(), l = 0, r = 0, result = 0;
        while(r < n) {
            minHeap.push({nums[r], r});
            maxHeap.push({nums[r], r});
            while (maxHeap.top().first - minHeap.top().first > limit) {
                l++;
                while(minHeap.top().second < l)
                    minHeap.pop();
                while(maxHeap.top().second < l)
                    maxHeap.pop();
            }
            result = max(result, ++r - l);
        }
        return result;
    }
};