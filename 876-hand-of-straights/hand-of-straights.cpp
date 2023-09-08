class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) {
            return false;
        }
        map<int,int> mp;
        for(int& num : hand) {
            mp[num]++;
        }
        for(int i = 0; i < hand.size() / groupSize; i++) {
            int top = mp.begin()->first;
            for(int j = top; j < top + groupSize; j++) {
                if(mp[j]-- == 0) {
                    return false;
                }
                if(mp[j] == 0) {
                    mp.erase(j);
                }
            }
        }
        return true;
    }
};