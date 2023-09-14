class Solution {
private:
    string getNext(string curr) {
        string prev = "", next = "";
        prev += curr[0];
        int prefix = 0;
        for(int i = 0; i < curr.size(); i++) {
            if(curr[i] == prev[0]) {
                prefix++;
                continue;
            }
            next += to_string(prefix) + prev;
            prefix = 1;
            prev = curr[i];
        }
        next += to_string(prefix) + prev;
        return next;
    }
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i = 1; i < n; i++) {
            result = getNext(result);
        }
        return result;
    }
};