class Solution {
private:
    int getSlimy(string &s, unordered_set<string> &ust, int idx) {
        if (idx == s.size()) {
            return 0;
        }
        int maxSplit = 0;
        string temp;
        for (int i = idx; i < s.size(); ++i) {
            temp += s[i];
            if (!ust.count(temp)) {
                ust.insert(temp);
                maxSplit = max(maxSplit, 1 + getSlimy(s, ust, i + 1));
                ust.erase(temp);
            }
        }
        return maxSplit;
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> ust;
        return getSlimy(s, ust, 0);
    }
};