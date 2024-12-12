class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long result = accumulate(gifts.begin(), gifts.end(), 0ll);
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while (k-- && pq.top()) {
            result -= pq.top() - sqrt(pq.top());
            pq.push(sqrt(pq.top()));
            pq.pop();
        }
        return result;
    }
};