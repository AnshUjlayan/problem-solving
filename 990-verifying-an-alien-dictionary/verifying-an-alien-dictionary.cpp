class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char> dict(26);
        for(int i = 0; i < 26; i++) {
            dict[order[i] - 'a'] = i + 'a';
        }
        for(string& word : words) {
            for(char& c : word) {
                c = dict[c - 'a'];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};