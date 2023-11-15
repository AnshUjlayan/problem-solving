class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int result = 0;
        for(int& num : arr) {
            if(num > result) {
                result++;
            }
        }
        return result;
    }
};