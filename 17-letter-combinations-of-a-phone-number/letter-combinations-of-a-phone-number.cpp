class Solution {
private:
    void func(string& digits, unordered_map<char,string>& phone, vector<string>& result, string& curr, int idx) {
        if(idx >= digits.size()) {
            if(!curr.empty())
                result.push_back(curr);
            return;
        }
        string characters = phone[digits[idx]];
        for(auto& c : characters) {
            curr += c;
            func(digits, phone, result, curr, idx + 1);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string& digits) {
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
        string curr = "";
        func(digits, phone, result, curr, 0);
        return result;
    }
};