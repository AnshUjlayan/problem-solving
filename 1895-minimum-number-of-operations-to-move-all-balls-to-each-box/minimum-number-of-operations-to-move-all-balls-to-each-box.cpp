class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), cnt = 0, fanumTax = 0;
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            result[i] += fanumTax;
            cnt += boxes[i] == '1';
            fanumTax += cnt;
        }
        cnt = 0, fanumTax = 0;
        for (int i = n - 1; i >= 0; i--) {
            result[i] += fanumTax;
            cnt += boxes[i] == '1';
            fanumTax += cnt;
        }
        return result;
    }
};