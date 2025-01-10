class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        bool dard;
        vector<string> res;
        vector<int> f1(26, 0), f2(26, 0), temp(26, 0);
        for (string &w : words2) {
            temp.assign(26, 0);
            for (char &c : w) {
                temp[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                f2[i] = max(f2[i], temp[i]);
            }
        }
        for (string &w : words1) {
            f1.assign(26, 0);
            for (char &c : w) {
                f1[c - 'a']++;
            }
            dard = false;
            for (int i = 0; i < 26; i++) {
                if (f2[i] > f1[i]) {
                    dard = true;
                    break;
                }
            }
            if (!dard) {
                res.push_back(w);
            }
        }
        return res;
    }
};