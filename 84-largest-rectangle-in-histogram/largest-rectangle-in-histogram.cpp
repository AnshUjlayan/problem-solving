class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0, n = heights.size();
        stack<int> stk;
        vector<int> leftBounds(n), rightBounds(n);
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            leftBounds[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        while(!stk.empty()) {
            stk.pop();
        }
        for(int i = n - 1; i >= 0; i--) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            rightBounds[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        for(int i = 0; i < n; i++) {
            int area = heights[i] * (rightBounds[i] - leftBounds[i] - 1);
            result = max(result, area);
        }
        return result;
    }
};