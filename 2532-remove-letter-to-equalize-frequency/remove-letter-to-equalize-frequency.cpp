class Solution {
private:
    bool check(vector<int>& freq) {
        int goalFreq = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                goalFreq = freq[i];
                break;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0 && freq[i] != goalFreq) {
                return false;
            }
        }
        return true;
    }
public:
    bool equalFrequency(string word) {
        vector<int> freq(26, 0);
        for(char& c : word) {
            freq[c - 'a']++;
        }
        for(char& c : word) {
            freq[c - 'a']--;
            if(check(freq)) {
                return true;
            }
            freq[c - 'a']++;
        }
        return false;
    }
};