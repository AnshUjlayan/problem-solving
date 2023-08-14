class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        int a = 1, b = 1;
        int result = 1;
        for(int i = n - 2; i >= 0; i--) {
            result = a + b;
            b = a;
            a = result;
        }
        return result;
    }
};