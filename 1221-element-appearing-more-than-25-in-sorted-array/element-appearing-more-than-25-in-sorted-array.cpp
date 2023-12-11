class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), l = 0, r = 0;
        double thresh = (double)n / 4;
        while(r < n) {
            if((++r - l) > thresh) {
                return arr[l];
            }
            if(arr[l] != arr[r]) {
                l = r;
            }
        }
        return -1;
    }
};