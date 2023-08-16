class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int l = 0, r = 0;
        while(r < k) {
            while(!dq.empty() && dq.back() < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(nums[r++]);
        }
        result.push_back(dq.front());
        while(r < nums.size()) {
            if(dq.front() == nums[l++]) {
                dq.pop_front();
            }
            while(!dq.empty() && dq.back() < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(nums[r++]);
            result.push_back(dq.front());
        }
        return result;
    }
};