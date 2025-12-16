class Solution {
public:
    void updateFen(vector<int>& fen, int idx, int delta) {
        while (idx < fen.size()) {
            fen[idx] += delta;
            idx += idx & -idx;
        }
    }

    int sumFen(vector<int>& fen, int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += fen[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    void update(vector<int>& fen, string& s, int idx) {
        s[idx] = s[idx] == 'A' ? 'B' : 'A';
        if (idx - 1 >= 0) {
            updateFen(fen, idx + 1, s[idx] == s[idx - 1] ? 1 : -1);
        }
        if (idx + 1 < s.size()) {
            updateFen(fen, idx + 2, s[idx] == s[idx + 1] ? 1 : -1);
        }
    }

    int getRes(vector<int>& fen, int l, int r) {
        return sumFen(fen, r + 1) - sumFen(fen, l + 1);
    }

    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> res, fen(n + 1, 0);

        for (int i = 1; i < n; i++) {
            fen[i + 1] = s[i] == s[i - 1];
        }

        for (int i = 1; i < n + 1; i++) {
            int parent = i + (i & -i);
            if (parent < n + 1) {
                fen[parent] += fen[i];
            }
        }
        for (auto& q : queries) {
            if (q[0] == 1) {
                update(fen, s, q[1]);
            } else {
                res.push_back(getRes(fen, q[1], q[2]));
            }
        }

        return res;
    }
};