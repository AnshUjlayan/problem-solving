class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(), s.rend());
        *find(s.rbegin(), s.rend(), '1') = '0', *(s.end() - 1) = '1';
        return s;
    }
};