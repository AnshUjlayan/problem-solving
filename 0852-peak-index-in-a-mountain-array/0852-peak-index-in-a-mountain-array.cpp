class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(mid < arr.size() - 1 && arr[mid + 1] >= arr[mid])
                low = mid + 1;
            else if(mid > 0 && arr[mid - 1] >= arr[mid])
                high = mid - 1;
            else
                return mid;
        }
        return high;
    }
};