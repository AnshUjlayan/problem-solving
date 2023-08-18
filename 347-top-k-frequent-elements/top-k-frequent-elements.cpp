class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> ump;
        priority_queue<pair<int,int>> pq;
        for(int num : nums) {
            ump[num]++;
        }
        for(auto x : ump) {
        pq.push({x.second, x.first});
        }
        for(int i = 0; i < k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};