class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0, l = 0, r = height.size() - 1;
        while(l < r) {
            int volume = min(height[l], height[r]) * (r - l);
            result = max(result, volume);
            if(height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return result;
    }
};