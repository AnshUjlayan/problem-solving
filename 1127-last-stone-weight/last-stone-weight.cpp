class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(abs(x - y) > 0) {
                pq.push(abs(x - y));
            }
        }
        return pq.size() ? pq.top() : 0;
    }
};