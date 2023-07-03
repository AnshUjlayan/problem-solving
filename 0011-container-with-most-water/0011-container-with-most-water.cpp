class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mod = 1e9 + 7, result = 0, l = 0, r = heights.size() - 1;
        while(l < r) {
            int vol = ((r - l) * min(heights[l], heights[r])) % mod;
            result = max(result, vol);
            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return result;
    }
};