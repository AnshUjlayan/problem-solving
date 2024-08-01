class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result = 0;
        for(string& detail : details) {
            result += stoi(detail.substr(11, 2)) > 60;
        }
        return result;
    }
};