class Solution {
private:
    string rollFront(string key, int idx) {
        key[idx]++;
        if (key[idx] > '9') {
            key[idx] = '0';
        }
        return key;
    }
    string rollBack(string key, int idx) {
        key[idx]--;
        if (key[idx] < '0') {
            key[idx] = '9';
        }
        return key;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if(dead.count("0000")) return -1;
        queue<string> q;
        q.push("0000");
        int result = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string key = q.front();
                q.pop();
                if (key == target)
                    return result;
                for (int j = 0; j < 4; j++) {
                    string next = rollFront(key, j);
                    string prev = rollBack(key, j);
                    if (!dead.count(next)) {
                        q.push(next);
                        dead.insert(next);
                    }
                    if (!dead.count(prev)) {
                        q.push(prev);
                        dead.insert(prev);
                    }
                }
            }
            result++;
        }
        return -1;
    }
};