class Solution {
private:
    struct Trie {
        string str;
        bool end;
        unordered_map<string, Trie*> children;
        Trie(string str) : str(str), end(false) {}
    };

    void pain(vector<vector<string>>& suffer, vector<string>& temp, Trie* curr) {
        if (curr->end) {
            suffer.push_back(temp);
            return;
        }
        for (auto& child : curr->children) {
            temp.push_back(child.second->str);
            pain(suffer, temp, child.second);
            temp.pop_back();
        }
    }

public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> temp, result;
        vector<vector<string>> suffer;
        Trie* head = new Trie("-");
        for (string& f : folder) {
            stringstream ss(f);
            string s;
            Trie* curr = head;
            while (getline(ss, s, '/')) {
                if (!s.empty()) {
                    if (curr->children[s] == nullptr) {
                        curr->children[s] = new Trie(s);
                    }
                    curr = curr->children[s];
                }
            }
            curr->end = true;
        }
        pain(suffer, temp, head);
        for (vector<string>& dard : suffer) {
            string res = "/" + accumulate(dard.begin(), dard.end(), string(""),
                                          [](const string& a, const string& b) {
                                              return a.empty() ? b : a + '/' + b;
                                          });
            result.push_back(res);
        }
        return result;
    }
};