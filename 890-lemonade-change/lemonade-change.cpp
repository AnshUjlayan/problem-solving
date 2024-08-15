class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int& bill : bills) {
            bill -= 5;
            ++five;
            if (!bill)
                continue;
            bill -= 5;
            five -= 2;
            if (bill)
                if (ten > 0)
                    --ten;
                else
                    five -= 2;
            else
                ++ten;

            if (five < 0 || ten < 0)
                return false;
        }
        return true;
    }
};