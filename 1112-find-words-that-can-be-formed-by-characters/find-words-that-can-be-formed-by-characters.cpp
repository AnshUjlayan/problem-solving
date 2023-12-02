class Solution {
private:
    int getSlimy(vector<int> freq, string word) {
        for(char& c : word) {
            if(--freq[c - 'a'] < 0) {
                return 0;
            }
        }
        return word.size();
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26);
        for(char& c : chars) {
            freq[c - 'a']++;
        }
        int result = 0;
        for(auto& word : words) {
            result += getSlimy(freq, word);
        }
        return result;
    }
};