class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> mp(128);
        for(char& c : s) {
            mp[c].first++;
            mp[c].second = c;
        }
        sort(mp.rbegin(), mp.rend());
        string result = "";
        for(auto& [freq, c] : mp) {
            while(freq--) {
                result += c;
            }
        }
        return result;
    }
};