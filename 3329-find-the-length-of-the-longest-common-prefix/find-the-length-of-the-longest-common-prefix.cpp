class Solution {
private:
    struct Node {
        vector<Node*> next;
        Node() {
            next.resize(10, nullptr);
        }
    };

    void build(Node *trie, string num) {
        Node *curr = trie;
        for (char &c : num) {
            if (!curr->next[c - '0']) {
                curr->next[c - '0'] = new Node();
            }
            curr = curr->next[c - '0'];
        }
    }

    int prefix(Node *trie, string num) {
        int res = 0;
        Node *curr = trie;
        for (char &c : num) {
            if (!curr->next[c - '0']) {
                return res;
            }
            curr = curr->next[c - '0'];
            res++;
        }
        return res;
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int result = 0;
        Node *trie = new Node(); 
        for (int &num : arr1) {
            build(trie, to_string(num));
        }
        for (int &num : arr2) {
            result = max(result, prefix(trie, to_string(num)));
        }
        return result;
    }
};