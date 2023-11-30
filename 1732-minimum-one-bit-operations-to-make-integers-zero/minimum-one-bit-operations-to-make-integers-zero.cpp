class Solution {
public:
    int minimumOneBitOperations(int n) {
        int result = 0;
        int slime = 2;
        while(n) {
            if(n & 1) {
                result = slime - result - 1;
            }
            n >>= 1;
            slime <<= 1;
        }
        return result;
    }
};