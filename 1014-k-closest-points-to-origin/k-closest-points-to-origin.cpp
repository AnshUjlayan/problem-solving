class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq;
        for(auto& point : points) {
            int dist = pow(point[0], 2) + pow(point[1], 2);
            pq.push({dist, point});
        }
        while(k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};