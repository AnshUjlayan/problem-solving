class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> result(temperatures.size());
        for(int i = temperatures.size() - 1; i >= 0; i--) {
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }
            result[i] = 0;
            if(!stk.empty()) {
                result[i] = stk.top() - i;
            }
            stk.push(i);
        }
        return result;
    }
};