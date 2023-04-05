class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> ump;
        for(char c : s) {
            ump[c]++;
        }
        priority_queue<int> pq;
        for(auto x : ump) {
            pq.push(x.second);
        }
        int result = 0, last = pq.top() + 1;
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if(x != last) {
                last = x;
                continue;
            }
            result++;
            if(x - 1 > 0) {
                pq.push(x - 1);
            }    
        }
        return result;
    }
};