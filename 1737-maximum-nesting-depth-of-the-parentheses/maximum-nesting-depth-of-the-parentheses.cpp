class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0, depth = 0;
        for(char& c : s) {
            if (c == '(') depth++;
            else if (c == ')') depth--;
            maxDepth = max(maxDepth, depth);
        }
        return depth == 0 ? maxDepth : -1;
    }
};