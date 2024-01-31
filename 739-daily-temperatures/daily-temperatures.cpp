class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> result(n);
        while(--n >= 0) {
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[n]) {
                stk.pop();
            }
            result[n] = (stk.empty() ? n : stk.top()) - n;
            stk.push(n);
        }
        return result;
    }
};