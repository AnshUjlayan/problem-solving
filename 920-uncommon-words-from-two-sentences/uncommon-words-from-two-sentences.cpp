class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        vector<string> res;
        istringstream iss1(s1), iss2(s2);
        string word;
        while (iss1 >> word) {
            wordCount[word]++;
        }
        while (iss2 >> word) {
            wordCount[word]++;
        }
        for (const auto& entry : wordCount) {
            if (entry.second == 1) {
                res.push_back(entry.first);
            }
        }
        return res;
    }
};