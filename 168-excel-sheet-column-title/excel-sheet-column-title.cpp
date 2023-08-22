class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while(columnNumber > 0) {
            int rem = (columnNumber - 1) % 26;
            columnNumber = (columnNumber - 1) / 26;
            result += (char)('A' + rem);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};