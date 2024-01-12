class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(), vowels = 0;
        set<char> st {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < n / 2; i++) {
            vowels += st.count(tolower(s[i])) ? 1 : 0;
        }
        for(int i = n / 2; i < n; i++) {
            vowels -= st.count(tolower(s[i])) ? 1 : 0;
        }
        return !vowels;
    }
};