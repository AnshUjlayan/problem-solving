class Solution {
private:
    vector<string> result, sentence;

    string getSentence() {
        string res;
        for (const string& word : sentence) {
            if (!res.empty()) res += " ";
            res += word;
        }
        return res;
    }

    void getSlimy(string& s, unordered_set<string>& wordDict, int idx) {
        if (idx == s.size()) {
            result.push_back(getSentence());
            return;
        }
        for (int i = idx; i < s.size(); ++i) {
            string substr = s.substr(idx, i - idx + 1);
            if (wordDict.count(substr)) {
                sentence.push_back(substr);
                getSlimy(s, wordDict, i + 1);
                sentence.pop_back();
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_set<string> ust(wordDict.begin(), wordDict.end());
        getSlimy(s, ust, 0);
        return result;
    }
};
