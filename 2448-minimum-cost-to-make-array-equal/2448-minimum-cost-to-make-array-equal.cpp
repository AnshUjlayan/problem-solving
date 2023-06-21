class Solution {
private:
    long long func(vector<int>& nums, vector<int>& cost, int num) {
        long long res = 0;
        for(int i = 0; i < nums.size(); i++)
            res += (long long)abs(nums[i] - num) * cost[i];
        return res;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long median = 0, total = 0, sum = 0;
        vector<pair<int,int>> vec;
        for(int i = 0; i < nums.size(); i++) {
            vec.push_back({nums[i], cost[i]});
            sum += cost[i];
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < nums.size(); i++) {
            if(total >= (sum + 1) / 2)
                break;
            total += vec[i].second;
            median = vec[i].first;
        }
        return func(nums, cost, median);
    }
};