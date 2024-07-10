class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (string& log : logs) {
            if (log[0] != '.') {
                depth++;
            }
            else if (log[0] == '.' && log[1] == '.') {
                depth = max(0, depth - 1);
            }
        }
        return depth;
    }
};