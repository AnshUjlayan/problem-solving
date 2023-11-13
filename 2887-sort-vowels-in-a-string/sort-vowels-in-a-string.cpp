class Solution {
public:
    string sortVowels(string s) {
        string vowels;
        auto isVowel = [&](char c) -> bool {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        for(char& c : s) {
            if(isVowel(c)) {
                vowels.push_back(c);
            }
        }
        sort(vowels.rbegin(), vowels.rend());
        for(char& c : s) {
            if(isVowel(c)) {
                c = vowels.back();
                vowels.pop_back();
            }
        }
        return s;
    }
};