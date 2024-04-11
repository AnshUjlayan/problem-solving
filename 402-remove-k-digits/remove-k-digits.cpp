class Solution {
public:
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        stack<int> stk;
        string result = "0";
        int n = num.size(), idx = 0;
        vector<int> bound(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!stk.empty() && num[stk.top()] >= num[i]) {
                stk.pop();
            }
            bound[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        while(idx < n) {
            int diff = bound[idx] - idx;
            if(diff <= k && k) {
                idx = bound[idx];
                k -= diff;
                continue;
            }
            result += num[idx++];
        }
        string::iterator it = result.begin();
        while (++it != result.end()) {
            if (*it != '0') {
                break;
            }
        }
        return string(min(it, result.end() - 1), result.end());
    }
};