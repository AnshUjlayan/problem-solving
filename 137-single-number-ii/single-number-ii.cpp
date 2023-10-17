class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int uno = 0, dos = 0;
        for(int& num : nums) {
            uno = (uno ^ num) & ~dos;
            dos = (dos ^ num) & ~uno;
        }
        return uno;
    }
};