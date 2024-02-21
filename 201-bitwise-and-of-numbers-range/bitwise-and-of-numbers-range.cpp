class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        bitset<32> result;
        for(int i = 0; i < 32; i++) {
            int num = 1 << i;
            result[i] = num & left & right;
            result[i] = result[i] & (right - left <= num);
        }
        return (int)result.to_ulong();
    }
};