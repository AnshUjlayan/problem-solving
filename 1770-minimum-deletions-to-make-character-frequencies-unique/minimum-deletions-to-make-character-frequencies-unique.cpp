class Solution {
public:
    int minDeletions(string s) {
        unordered_set<char> ust;
        unordered_map<char,int> ump;
        unordered_map<int,int> freq;
        for(char& c : s) {
            ust.insert(c);
            ump[c]++;
        }
        for(auto& [key, val] : ump) {
            freq[val]++;
        }
        int result = 0;
        for(auto& c : ust) {
            while(freq[ump[c]] > 1) {
                freq[ump[c]--]--;
                if(ump[c] > 0) {
                    freq[ump[c]]++;
                }
                result++;
            }
        }
        return result;
    }
};