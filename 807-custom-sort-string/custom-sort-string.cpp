class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);
        string result = "";
        for(char& c : s) {
            freq[c - 'a']++;
        }
        for(char& c : order) {
            while(freq[c - 'a']--) {
                result += c;
            }
        }
        for(int i = 0; i < 26; i++) {
            while(freq[i]-- > 0) {
                result += i + 'a';
            }
        }
        return result;
    }
};