class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> ump;
        for (char c : s) {
            ump[c]++;
        }
        priority_queue<pair<int,char>> pq;
        deque<char> dq;
        for (const auto& entry : ump) {
            pq.push({entry.second, entry.first});
        }
        string result = "";
        while(!pq.empty()) {
            pair<int,int> front = pq.top();
            pq.pop();
            if(result.empty() || result.back() != front.second) {
                result += front.second;
                if(--front.first > 0) {
                    pq.push({front.first, front.second});
                }
            }
            else {
                if(pq.empty()) {
                    return "";
                }
                pair<int,int> rm = pq.top();
                pq.pop();
                result += rm.second;
                if(--rm.first > 0) {
                    pq.push(rm);
                }
                pq.push(front);
            }
        }
        return result;
    }
};