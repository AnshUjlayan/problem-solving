class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int result = 0, n = arr.size();
        for(int i = 0; i < n; i++) {
            int XOR = 0;
            for(int j = i; j < n; j++) {
                XOR ^= arr[j];
                if(!XOR)
                    result += j - i;
            }
        }
        return result;
    }
};