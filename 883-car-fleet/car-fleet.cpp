class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i = 0; i < speed.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        stack<double> stk;
        for(int i = cars.size() - 1; i >= 0; i--) {
            double thisEnd = (double)(target - cars[i].first) / (double)cars[i].second;
            if(stk.empty() || stk.top() < thisEnd) {
                stk.push(thisEnd);
            }
        }
        return stk.size();
    }
};