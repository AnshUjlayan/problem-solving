class Solution {
private:
    int checkVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return 1;
        }
        return 0;
    }
public:
    int maxVowels(string s, int k) {
        int result = 0, temp = 0, left = 0, right = 0;
        while((left <= right) && (right < s.size())) {
            if(right - left < k) {
                temp += checkVowel(s[right++]);
                result = max(result, temp);
                continue;
            }
            temp = temp - checkVowel(s[left++]) + checkVowel(s[right++]);
            result = max(result, temp);
        }
        return result;
    }
};