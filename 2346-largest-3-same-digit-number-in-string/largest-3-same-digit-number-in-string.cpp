class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "";
        int n = num.size(), l = 0, r = 0;
        while(r < n) {
            while(num[r] == num[l]) {
                r++;
            }
            if(r - l >= 3 && num[l] > result[0]) {
                result = num.substr(l, 3);
            }
            l = r;
        }
        return result;
    }
};