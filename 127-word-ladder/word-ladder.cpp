class Solution {
private:
    unordered_map<string,vector<string>> makeAdj(vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string,vector<string>> adj(n);
        unordered_set<string> dict(wordList.begin(), wordList.end());
        for(int i = 0; i < n; i++) {
            string temp = wordList[i];
            for(int j = 0; j < temp.size(); j++) {
                char c = temp[j];
                for(int k = 0; k < 26; k++) {
                    temp[j] = 'a' + k;
                    if(dict.find(temp) != dict.end()) {
                        adj[wordList[i]].push_back(temp);
                    }
                }
                temp[j] = c;
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