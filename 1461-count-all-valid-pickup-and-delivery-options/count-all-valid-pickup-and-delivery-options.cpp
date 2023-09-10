class Solution {
public:
    int countOrders(int n) {
        long result = 1;
        for(int i = 1; i <= n; i++) {
            result = result * (i * 2 - 1) * i % (long)(1e9 + 7);
        }
        return result;
    }
};