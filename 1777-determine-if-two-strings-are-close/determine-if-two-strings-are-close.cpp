class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26, 0), freq2(26, 0);
        set<int> st1, st2;
        for(char& c : word1) {
            freq1[c - 'a']++;
            st1.insert(c - 'a');
        }
        for(char& c : word2) {
            freq2[c - 'a']++;
            st2.insert(c - 'a');
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2 && st1 == st2;
    }
};