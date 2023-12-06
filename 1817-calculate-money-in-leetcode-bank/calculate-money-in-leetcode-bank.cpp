class Solution {
public:
    int totalMoney(int n) {
        int result = 0, i = 1, cnt = 0, inc = 1;
        while(n) {
            if(cnt == 7) {
                cnt = 0;
                inc++;
                i = inc;
            }
            result += i++;
            cnt++;
            n--;
        }
        return result;
    }
};