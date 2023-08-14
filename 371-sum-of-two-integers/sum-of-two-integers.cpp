class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            int sum1 = a ^ b;
            int sum2 = a & b;
            sum2 <<= 1;
            a = sum1;
            b = sum2;
        }
        return a;
    }
};