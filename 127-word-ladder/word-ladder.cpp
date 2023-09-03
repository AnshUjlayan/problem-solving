class Solution {
private:
    bool similar(string a, string b) {
        int cnt = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                cnt++;
            }
        }
        return cnt <= 1;
    }
    unordered_map<string,vector<string>> makeAdj(vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string,vector<string>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(similar(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        return adj;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string,vector<string>> adj = makeAdj(wordList);
        unordered_set<string> visited;
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        visited.insert(beginWord);
        while(!q.empty()) {
            pair<string,int> currWord = q.front();
            q.pop();
            if(currWord.first == endWord) {
                return currWord.second;
            }
            for(auto& neighbour : adj[currWord.first]) {
                if(visited.find(neighbour) == visited.end()) {
                    q.push({neighbour, currWord.second + 1});
                    visited.insert(neighbour);
                }
            }
        }
        return 0;
    }
};