class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size(), result = 0;
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.back() <= i)
                dq.pop_back();
            int cnt = dq.size() + nums[i];
            if (!(cnt & 1)) {
                if (i + k > n)
                    return -1;
                result++;
                dq.push_front(i + k);
            }
        }
        return result;
    }
};