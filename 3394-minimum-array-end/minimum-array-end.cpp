class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64> mask(n - 1), res(x);
        int i = 0, j = 0;
        while (i < 64) {
            if (!res[i]) {
                res[i] = mask[j++];
            }
            i++;
        }
        return res.to_ullong();
    }
};