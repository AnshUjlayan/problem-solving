class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());
        int result = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            if (!st.count(i)) {
                if (sum + i > maxSum) {
                    break;
                }
                sum += i;
                result++;
            }
        }
        return result;
    }
};