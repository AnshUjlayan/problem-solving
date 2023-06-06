class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), a = arr[1] - arr[0];
        for(int i = 0; i < n - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            if(a != diff)
                return false;
        }
        return true;
    }
};