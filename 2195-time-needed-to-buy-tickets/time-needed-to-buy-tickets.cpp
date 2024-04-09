class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int idx = 0, n = tickets.size(), time = 0;
        while(true) {
            if(tickets[idx]-- > 0) {
                time++;
            }
            if(idx == k && !tickets[idx]) {
                return time;
            }
            idx++;
            idx %= n;
        }
        return time;
    }
};
