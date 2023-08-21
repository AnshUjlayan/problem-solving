class Solution {
private:
    bool canEat(vector<int>& piles, int h, int speed) {
        long long timeTaken = 0;
        for(int pile : piles) {
            timeTaken += ceil((double)pile / speed);
        }
        return timeTaken <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int result = -1, l = 1, r = 1e9;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(canEat(piles, h, mid)) {
                result = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return result;
    }
};