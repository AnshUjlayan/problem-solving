class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        bitset<32> bits(n);
        for(int i = 0; i < 32; i++) {
            result += bits[i];
        }
        return result;
    }
};