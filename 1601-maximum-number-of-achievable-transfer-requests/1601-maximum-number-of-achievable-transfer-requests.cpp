class Solution {
private:
    int func(vector<vector<int>>& requests, vector<int>& deg, int& n, int reqCount, int idx) {
        if(idx >= requests.size()) {
            for(int i = 0; i < n; i++) {
                if(deg[i] != 0) {
                    return 0;
                }
            }
            return reqCount;
        }
        deg[requests[idx][0]]--;
        deg[requests[idx][1]]++;
        int func1 = func(requests, deg, n, reqCount + 1, idx + 1);
        deg[requests[idx][0]]++;
        deg[requests[idx][1]]--;
        return max(func1, func(requests, deg, n, reqCount, idx + 1));
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> deg(n, 0);
        return func(requests, deg, n, 0, 0);
    }
};