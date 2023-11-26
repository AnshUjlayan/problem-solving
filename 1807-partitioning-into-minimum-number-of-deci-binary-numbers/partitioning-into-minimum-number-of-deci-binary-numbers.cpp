class Solution {
public:
    int minPartitions(string n) {
        char res = '0';
        for(char& c : n) {
            res = max(res, c);
        }
        return res - '0';
    }
};