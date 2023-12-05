class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int m = s.size(), n = shifts.size();
        int rotations = 0, ptr = 0;
        auto shift = [&](int idx) {
            rotations %= 26;
            int moves = (s[idx] - 'a' + rotations) % 26;
            moves += moves < 0 ? 26 : 0;
            s[idx] = moves + 'a';
        };
        vector<int> sum(m + 1, 0);
        for(int i = 0; i < n; i++) {
            sum[shifts[i][0]] += shifts[i][2] == 0 ? -1 : 1;
            sum[shifts[i][1] + 1] -= shifts[i][2] == 0 ? -1 : 1;
        }
        for(int i = 0; i < m; i++) {
            rotations += sum[i];
            shift(i);
        }
        return s;
    }
};