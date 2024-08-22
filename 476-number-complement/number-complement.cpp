class Solution {
public:
    int findComplement(int num) {
        return (int)(num ^ INT_MAX) & ((int)pow(2, floor(log2(num))) - 1);
    }
};