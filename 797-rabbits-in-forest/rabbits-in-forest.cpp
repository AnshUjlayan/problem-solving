class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int,int> mp;
        for (int &x : answers) {
            mp[x]++;
        }
        for (auto &[k, v] : mp) {
            res += (k + 1) * ((v + k) / (k + 1));
        }
        return res;
    }
};