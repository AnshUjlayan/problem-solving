class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(auto& match : matches) {
            mp[match[0]];
            mp[match[1]]++;
        }
        vector<int> winner, loser;
        for(auto& [key, val] : mp) {
            if(val == 0) {
                winner.push_back(key);
            }
            else if(val == 1) {
                loser.push_back(key);
            }
        }
        return {winner, loser};
    }
};