class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while(x != 0) {
            int temp = x % 10;
            x /= 10;
            
            result *= 10;
            result += temp;
            if(result > INT_MAX || result < INT_MIN) {
                return 0;
            }
        }
        return (int)result;
    }
};