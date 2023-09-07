class Solution {
public:
    bool canJump(vector<int>& nums) {
        int fuel = 0;
        for(int num : nums) {
            if(fuel < 0) {
                return false;
            }
            fuel = max(fuel, num) - 1;
        }
        return true;
    }
};