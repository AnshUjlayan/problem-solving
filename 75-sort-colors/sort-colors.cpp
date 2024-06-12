class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zc = 0, oc = 0;
        for(int& num : nums) {
            zc += num == 0 ? 1 : 0;
            oc += num == 1 ? 1 : 0;
        }
        int ptr = 0;
        while(zc--)
            nums[ptr++] = 0;
        while(oc--)
            nums[ptr++] = 1;
        while(ptr < nums.size())
            nums[ptr++] = 2;
    }
};