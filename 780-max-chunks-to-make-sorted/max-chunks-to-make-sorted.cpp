class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int result = 0, n = arr.size();
        vector<bool> have(n, false);
        for (int i = n - 1; i >= 0; i--) {
            have[arr[i]] = true;
            result++;
            for (int j = i; j < n; j++) {
                if (have[j] == false) {
                    result--;
                    break;
                }
            }
        }
        return result;
    }
};