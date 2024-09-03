class Solution {
public:
    int getLucky(string s, int k) {
        string str = "";
        for (char& c : s)
            str += to_string(c - 'a' + 1);
        
        while (k--) {
            int res = 0;
            for (char& c : str)
                res += c - '0';
            str = to_string(res);
        }
        return stoi(str);
    }
};