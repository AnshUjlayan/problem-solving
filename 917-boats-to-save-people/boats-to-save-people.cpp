class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(people.begin(), people.end());
        vector<int>::iterator l = people.begin();
        vector<int>::iterator r = --people.end();
        int result = 0;
        while(l <= r) {
            if(*l + *r <= limit) {
                l++;
            }
            r--;
            result++;
        }
        return result;
    }
};