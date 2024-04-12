class Solution {
public:
    int trap(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int result = 0, n = height.size(), maxElement = 0;
        vector<int> right(n);
        for(int i = n - 1; i >= 0; --i) {
            maxElement = max(maxElement, height[i]);
            right[i] = maxElement;
        }
        maxElement = 0;
        for(int i = 0; i < n; i++) {
            maxElement = max(maxElement, height[i]);
            result += min(maxElement, right[i]) - height[i];
        }
        return result;
    }
};