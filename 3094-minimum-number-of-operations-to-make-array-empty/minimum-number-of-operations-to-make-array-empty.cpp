class Solution {
private:
    int getSlimy(int n) {
        if(n < 2) {
            return -1;
        }
        if(n == 2 || n == 3) {
            return 1;
        }
        return n / 3 + (n % 3 == 0 ? 0 : 1);
    }
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        int result = 0;
        for(int& num : nums) {
            mp[num]++;
        }
        for(auto& [key, val] : mp) {
            int calc = getSlimy(val);
            if(calc == -1) {
                return -1;
            }
            result += calc;
        }
        return result;
    }
};