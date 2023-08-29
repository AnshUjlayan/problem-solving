class Solution {
private:
    bool isPalindrome(string str) {
        int l = 0, r = str.size() - 1;
        while(l <= r) {
            if(str[l++] != str[r--]) {
                return false;
            }
        }
        return true;
    }
    void func(vector<vector<string>>& result, vector<string>& subset, string s) {
        if(s.empty()) {
            result.push_back(subset);
            return;
        }
        for(int i = 1; i <= s.size(); i++) {
            if(isPalindrome(s.substr(0, i))) {
                subset.push_back(s.substr(0, i));
                func(result, subset, s.substr(i));
                subset.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> subset;
        func(result, subset, s);
        return result;
    }
};