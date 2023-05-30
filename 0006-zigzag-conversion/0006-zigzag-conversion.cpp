class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1 || n <= numRows) {
            return s;
        }
        string arr[numRows];
        int x = 0, dir = -1;
        for(char& c : s) {
            arr[x] += c;
            if(x == 0 || x == numRows - 1) {
                dir *= -1;
            }
            x += dir;
        }
        string result = "";
        for(const string& str : arr) {
            result += str;
        }
        return result;
    }
};