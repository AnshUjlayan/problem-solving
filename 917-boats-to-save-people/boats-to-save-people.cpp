const int ZERO = [] () {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
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