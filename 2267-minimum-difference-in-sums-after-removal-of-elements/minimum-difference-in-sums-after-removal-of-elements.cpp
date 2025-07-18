class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int seg = nums.size() / 3;
        long long sum = 0, mn = LLONG_MAX, mx = LLONG_MIN, res = LLONG_MAX;

        priority_queue<int> maxHeap(nums.begin(), nums.begin() + seg);
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin() + seg + seg, nums.end());
        vector<long long> right(seg + 1);

        mx = sum = accumulate(nums.begin() + seg + seg, nums.end(), 0ll);
        right[seg] = mx;
        for (int i = seg + seg - 1; i >= seg; i--) {
            minHeap.push(nums[i]);
            sum = sum + nums[i] - minHeap.top();
            right[i - seg] = mx = max(mx, sum);
            minHeap.pop();
        }

        mn = sum = accumulate(nums.begin(), nums.begin() + seg, 0ll);
        res = min(res, mn - right[0]);
        for (int i = seg; i < seg + seg; i++) {
            maxHeap.push(nums[i]);
            sum = sum + nums[i] - maxHeap.top();
            mn = min(mn, sum);
            res = min(res, mn - right[i - seg + 1]);
            maxHeap.pop();
        }

        return res;
    }
};