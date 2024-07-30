class Solution {
public:
    int minimumDeletions(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        s += 'b';
        int n = s.size(), cnt = 0, result = 1e9;
        vector<int> count(n);
        
        for (int i = n - 1; i >= 0; i--) {
            cnt += s[i] == 'a' ? 1 : 0;
            count[i] = cnt;
        }
        
        cnt = 0;
        for (int i = 0; i < n; i++) {
            result = min(result, cnt + count[i]);
            cnt += s[i] == 'b' ? 1 : 0;
        }
        
        return result;
    }
};