class Solution {
private:
    struct Trie {
        int end = 0;
        Trie *next[26] = {};
    };

    void addWord(Trie* trie, string &word) {
        Trie* curr = trie;
        for (char &c : word) {
            if (!curr->next[c - 'a']) {
                curr->next[c - 'a'] = new Trie();
            }
            curr = curr->next[c - 'a'];
            curr->end++;
        }
    }

    int getScore(Trie* trie, string &word) {
        Trie* curr = trie;
        int res = 0;
        for (char &c : word) {
            curr = curr->next[c - 'a'];
            res += curr->end;
        }
        return res;
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> result;
        Trie *trie = new Trie();
        for (string& word : words) {
            addWord(trie, word);
        }
        for (string& word : words) {
            result.push_back(getScore(trie, word));
        }
        return result;
    }
};