#pragma GCC optimize("O3")
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        auto idx = sentence.begin();
        auto comp = [] (string& x, string& y) -> bool { return x.size() < y.size(); };
        sort(dictionary.begin(), dictionary.end(), comp);
        while (idx < sentence.end()) {
            for (string& word : dictionary) {
                if (distance(idx, sentence.end()) >= word.size() && string(idx, idx + word.size()) == word) {
                    sentence.replace(idx, find(idx, sentence.end(), ' '), word.begin(), word.end());
                    break;
                }
            }
            idx = find(idx, sentence.end(), ' ') + 1;
        }
        return sentence;
    }
};
