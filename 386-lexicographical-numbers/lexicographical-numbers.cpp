class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> temp;
        vector<int> res;
        while (n) {
            temp.push_back(to_string(n--));
        }
        sort(temp.begin(), temp.end());
        for (string& str : temp) {
            res.push_back(stoi(str));
        }
        return res;
    }
};