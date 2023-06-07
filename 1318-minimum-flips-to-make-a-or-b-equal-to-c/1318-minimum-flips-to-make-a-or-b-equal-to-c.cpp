class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32> x(a), y(b), z(c);
        int result = 0;
        for(int i = 32; i >= 0; i--) {
            if(!z[i]) {
                result += x[i] + y[i];
            }
            else if(z[i]) {
                result += 1 - (x[i] || y[i]);
            }
        }
        return result;
    }
};