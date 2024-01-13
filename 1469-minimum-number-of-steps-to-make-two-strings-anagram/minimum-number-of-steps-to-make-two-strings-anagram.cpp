class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size(), result = 0;
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for(int& num : freq) {
            result += num < 0 ? abs(num) : 0;
        }
        return result;
    }
};