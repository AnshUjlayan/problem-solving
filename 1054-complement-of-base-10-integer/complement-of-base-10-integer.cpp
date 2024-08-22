class Solution {
public:
    int bitwiseComplement(int n) {
        return n ? (int)(n ^ INT_MAX) & ((int)pow(2, floor(log2(n))) - 1) : 1;
    }
};