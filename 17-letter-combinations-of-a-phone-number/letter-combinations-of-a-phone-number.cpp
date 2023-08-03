class Solution {
private:
    void func(string& digits, unordered_map<char, string>& phone, vector<string>& result, string& ans, int idx) {
        if(idx == digits.size()) {
            if(!ans.empty())
                result.push_back(ans);
            return;
        }
        for(char& c : phone[digits[idx]]) {
            ans += c;
            func(digits, phone, result, ans, idx + 1);
            ans.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phone {
            {'2', "abc"}, 
            {'3', "def"}, 
            {'4', "ghi"}, 
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> result;
        string ans = "";
        func(digits, phone, result, ans, 0);
        return result;
    }
};