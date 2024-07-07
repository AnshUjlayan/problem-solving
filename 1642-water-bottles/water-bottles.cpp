class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = 0, empty = 0;
        while(numBottles) {
            result += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty %= numExchange;
        }
        return result;
    }
};