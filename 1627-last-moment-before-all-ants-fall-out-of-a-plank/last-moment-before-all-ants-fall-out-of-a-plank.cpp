class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        for(int& num : left) {
            result = max(result, num);
        }
        for(int& num : right) {
            result = max(result, n - num);
        }
        return result;
    }
};