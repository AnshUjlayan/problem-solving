class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0, r = sqrt(c);
        while(l <= r) {
            long long dard = pow(l, 2) + pow(r, 2);
            if(dard == c) {
                return true;
            }
            else if(dard > c) {
                r--;
            }
            else {
                l++;
            }
        }
        return false;
    }
};