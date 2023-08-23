class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> ump = {
            {1, "I"},
            {4, "VI"},
            {5, "V"},
            {9, "XI"},
            {10, "X"},
            {40, "LX"},
            {50, "L"},
            {90, "CX"},
            {100, "C"},
            {400, "DC"},
            {500, "D"},
            {900, "MC"},
            {1000, "M"}
        };
        int mul = 1;
        string result = "";
        while(num > 0) {
            int rem = num % 10;
            num /= 10;
            if(rem == 9) {
                string c = ump[(9 * mul)];
                result += c;
                rem -= 9;
            }
            else if(rem >= 5) {
                while(rem > 5) {
                    string c = ump[(1 * mul)];
                    result += c;
                    rem--;
                }
                string c = ump[(5 * mul)];
                result += c;
                rem -= 5;
            }
            else if(rem == 4) {
                string c = ump[(4 * mul)];
                result += c;
                rem -= 4;
            }
            while(rem > 0) {
                string c = ump[(1 * mul)];
                result += c;
                rem--;
            }
            mul *= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};