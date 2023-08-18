class Solution {
private:
    void func(vector<string>& result, string& str, int n, int rem) {
        if(n == 0 && rem == 0) {
            result.push_back(str);
        }
        if(n) {
            str += '(';
            func(result, str, n - 1, rem + 1);
            str.pop_back();
        }
        if(rem) {
            str += ')';
            func(result, str, n, rem - 1);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str = "";
        func(result, str, n, 0);
        return result;
    }
};