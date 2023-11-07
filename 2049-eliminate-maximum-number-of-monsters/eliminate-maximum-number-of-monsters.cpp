class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double, vector<double>, greater<double>> pq;
        int result = 1;
        for(int i = 0; i < dist.size(); i++) {
            double arrivalTime = 1.0 * dist[i] / speed[i];
            pq.push(arrivalTime);
        }
        pq.pop();
        while(!pq.empty() && pq.top() > result) {
            pq.pop();
            result++;
        }
        return result;
    }
};