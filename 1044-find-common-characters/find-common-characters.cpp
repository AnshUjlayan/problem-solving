class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cmp(26, 0);
        int n = words.size();
        for(char& c : words[0]) {
            cmp[c - 97]++;
        }
        for(int i = 1; i < n; i++) {
            vector<int> temp(26, 0);
            for(char& c : words[i]) {
                temp[c - 97]++;
            }
            for(int j = 0; j < 26; j++) {
                if(cmp[j] != temp[j]) {
                    cmp[j] = min(cmp[j], temp[j]);
                }
            }
        }
        vector<string> result;
        for(int i = 0; i < 26; i++) {
            while(cmp[i]--) {
                result.push_back(string(1, char(97 + i)));
            }
        }
        return result;
    }
};