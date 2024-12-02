class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string temp;
        int result = 1;
        auto starts_with = [](string a, string b) -> bool {
            if (a.size() < b.size()) {
                return false;
            }
            for (int i = 0; i < b.size(); i++) {
                if (a[i] != b[i]) {
                    return false;
                }
            }
            return true;
        };
        while (ss >> temp) {
            if (starts_with(temp, searchWord)) {
                return result;
            }
            result++;
        }
        return -1;
    }
};