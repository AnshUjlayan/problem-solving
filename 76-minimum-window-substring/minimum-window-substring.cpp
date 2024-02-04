class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), req = 0, l = 0, r = 0;
        vector<int> dict1(58, 0), dict2(58, 0);
        pair<int,int> result {0, 1e9};
        for(char& c : t) {
            if(!dict1[c - 'A']++) req++;
        }
        while(r < n) {
            if(++dict2[s[r] - 'A'] == dict1[s[r++] - 'A']) {
                req--;
            }
            while(l < r && req <= 0) {
                if(result.second - result.first > r - l) {
                    result = {l, r};
                }
                if(dict2[s[l] - 'A']-- == dict1[s[l++] - 'A']) {
                    req++;
                }
            }
        }
        if(result.second == 1e9) result.second = 0;
        return s.substr(result.first, result.second - result.first);
    }
};