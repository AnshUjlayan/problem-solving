class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int result = 0, cnt = 0;
        vector<int> dict(26, 0);

        for (char& c : word)
            dict[c - 97]++;
        
        sort(dict.rbegin(), dict.rend());

        for (int i = 0; i < 26; i++) {
            if (!dict[i])
                break;
            cnt += i % 8 ? 0 : 1;
            result += dict[i] * cnt;
        }
        
        return result;
    }
};