class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string result = "";
        priority_queue<pair<int,int>> pq;
        vector<int> dict(26, 0);
        for (char c : s) {
            dict[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (dict[i] > 0) {
                pq.push({i, dict[i]});
            }
        }
        while (!pq.empty()) {
            auto [c, f] = pq.top();
            pq.pop();
            int end = min(repeatLimit, f);
            for (int i = 0; i < end; i++) {
                result += 'a' + c;
                f--;
            }
            if (pq.empty()) {
                break;
            }
            auto [c2, f2] = pq.top();
            pq.pop();
            if (f > 0) {
                pq.push({c, f});
                result += 'a' + c2;
                f2--;
            }
            if (f2 > 0) {
                pq.push({c2, f2});
            }
        }
        return result;
    }
};