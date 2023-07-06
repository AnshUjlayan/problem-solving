class Solution {
private:
    bool isPalindrome(string str) {
        int l = 0, r = str.size() - 1;
        while(l < r) {
            if(str[l++] != str[r--])
                return false;
        }
        return true;
    }
    void func(string& s, vector<vector<string>>& result, vector<string> str, int idx) {
        if(idx >= s.size()) {
            result.push_back(str);
            return;
        }
        for(int i = idx; i < s.size(); i++) {
            if(isPalindrome(s.substr(idx, i - idx + 1))) {
                str.push_back(s.substr(idx, i - idx + 1));
                func(s, result, str, i + 1);
                str.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> str;
        func(s, result, str, 0);
        return result;
    }
};