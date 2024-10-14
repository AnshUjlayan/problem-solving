class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long result = 0;
        while (k-- && pq.top() != 0) {
            result += pq.top();
            pq.push(ceil(1.0 * pq.top() / 3));
            pq.pop();
        }
        return result;
    }
};