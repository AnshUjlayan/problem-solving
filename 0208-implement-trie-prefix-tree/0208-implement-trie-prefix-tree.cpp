class Trie {
private:
    struct TrieNode {
        struct TrieNode* child[26];
        bool isEnd = false;
    };
    TrieNode* node;
public:
    Trie() {
        node = new TrieNode();
    }
    void insert(string word) {
        TrieNode* curr = node;
        for (char c : word) {
            if (curr->child[c - 'a'] == NULL) 
                curr->child[c - 'a'] = new TrieNode();
            curr = curr->child[c - 'a'];
        }
        curr->isEnd = true;
    }
    bool search(string word) {
        TrieNode* curr = node;
        for (char c : word) {
            if (curr->child[c - 'a'] == NULL) 
                return false;
            curr = curr->child[c - 'a'];
        }
        if (curr->isEnd) 
            return true;
        return false;
    }
    bool startsWith(string prefix) {
        TrieNode* curr = node;
        for (char c : prefix) {
            if (curr->child[c - 'a'] == NULL) 
                return false;
            curr = curr->child[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */