class Solution {
private:
    vector<vector<string>> result;
    vector<string> temp;

    bool isPalindrome(string &s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

    void getSlimy(string &s, int idx) {
        if (idx == s.size()) {
            result.push_back(temp);
            return;
        }
        for (int i = idx; i <= s.size(); ++i) {
            string substring = s.substr(idx, i - idx + 1);
            if (isPalindrome(substring)) {
                temp.push_back(substring);
                getSlimy(s, i + 1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        getSlimy(s, 0);
        return result;
    }
};