class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size(), count = 0, curr = 0, next = curr + 1;
        while(next < n && count < k) {
            if(arr[curr] > arr[next]) {
                count++;
            }
            else {
                count = 1;
                curr = next;
            }
            next++;
        }
        return arr[curr];
    }
};