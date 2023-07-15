class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int bit = 1;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(bit) {
                digits[i]++;
                bit = 0;
            }
            if(digits[i] == 10) {
                digits[i] = 0;
                bit = 1;
            }
            result.push_back(digits[i]);
        }
        if(bit) {
            result.push_back(1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};