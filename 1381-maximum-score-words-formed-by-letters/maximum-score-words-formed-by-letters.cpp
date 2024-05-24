class Solution {
private:
    int getSlimy(vector<string>& words, vector<int>& score, vector<int>& freq, int idx) {
        if(idx == words.size()) {
            return 0;
        }
        int result = getSlimy(words, score, freq, idx + 1);
        bool dard = false;
        int num = 0;
        for(char& c : words[idx]) {
            num += score[c - 'a'];
            if(!freq[c - 'a']--) {
                dard = true;
            }
        }
        result = max(result, !dard ? getSlimy(words, score, freq, idx + 1) + num : 0); 
        for(char& c : words[idx]) {
            freq[c - 'a']++;
        }
        
        return result;
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> wordScores, freq(26, 0);
        for(char& c : letters) {
            freq[c - 'a']++;
        }
        return getSlimy(words, score, freq, 0);
    }
};