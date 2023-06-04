class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int x = a.size() - 1;
        int y = b.size() - 1;
        while(x >= 0 || y >= 0) {
            int sum = carry;
            if(x >= 0)
                sum += a[x--] - '0';
            if(y >= 0)
                sum += b[y--] - '0';
            carry = sum > 1 ? 1 : 0;
            result += to_string(sum % 2);
        }
        if(carry)
            result += '1';
        reverse(result.begin(), result.end());
        return result;
    }
};