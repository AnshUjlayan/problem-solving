class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0, curr = 0;
        while(count < k && curr < n - 1) {
            int next = (curr + 1) % n;
            if(arr[curr] > arr[next]) {
                count++;
                swap(arr[curr], arr[next]);
            }
            else {
                count = 1;
            }
            curr = next;
        }
        return arr[curr];
    }
};