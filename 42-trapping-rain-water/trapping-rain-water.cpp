class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0, n = height.size(), curr = 0;
        vector<int> leftBound(n), rightBound(n);
        for(int i = 0; i < n; i++) {
            leftBound[i] = curr;
            curr = max(curr, height[i]);
        }
        curr = 0;
        for(int i = n - 1; i >= 0; i--) {
            rightBound[i] = curr;
            curr = max(curr, height[i]);
        }
        for(int i = 0; i < n; i++) {
            int temp = min(leftBound[i], rightBound[i]);
            if(temp > height[i]) {
                result += temp - height[i];
            }
        }
        return result;
    }
};