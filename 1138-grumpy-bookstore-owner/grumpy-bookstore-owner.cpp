class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), result = 0;
        vector<pair<int,int>> cust;
        for(int i = 0; i < n; i++) {
            if (grumpy[i]) {
                cust.push_back({i, customers[i]});
            } else {
                result += customers[i];
            }
        }
        int l = 0, r = 0, sum = 0, mx = 0;
        while (r < cust.size()) {
            sum += cust[r].second;
            while(cust[r].first - cust[l].first >= minutes) {
                sum -= cust[l++].second;
            }
            mx = max(mx, sum);
            r++;
        }
        return result + mx;
    }
};