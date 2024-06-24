class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size(), result = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top() <= i)
                pq.pop();
            int cnt = pq.size() + nums[i];
            if (!(cnt & 1)) {
                if (i + k > n)
                    return -1;
                result++;
                pq.push(i + k);
            }
        }
        return result;
    }
};