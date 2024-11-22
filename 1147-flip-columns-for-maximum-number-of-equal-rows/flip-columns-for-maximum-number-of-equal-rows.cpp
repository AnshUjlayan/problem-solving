class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int result = 0;
        unordered_map<string,int> ump;
        for (auto &row : matrix) {
            string s = "";
            for (auto &x : row) {
                s += x == row[0] ? '1' : '0';
            }
            ump[s]++;
        }
        auto flip = [](string s) {
            string res = "";
            for (char &c : s) {
                res += (char)('0' + '1' - c);
            }
            return res;
        };
        for (auto &[key, val] : ump) {
            result = max(result, val);
            string flipped = flip(key);
            if (ump.find(flipped) != ump.end()) {
                result = max(result, ump[flipped] + 1);
            }
        }
        return result;
    }
};