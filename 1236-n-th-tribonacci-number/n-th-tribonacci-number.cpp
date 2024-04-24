class Solution {
public:
    int tribonacci(int n) {
        if(!n) return 0;
        int a = 0, b = 1, c = 1;
        n -= 2;
        while(n-- > 0) {
            vector<int> temp = {a, b, c};
            a = temp[1];
            b = temp[2];
            c = temp[0] + temp[1] + temp[2];
        }
        return c;
    }
};