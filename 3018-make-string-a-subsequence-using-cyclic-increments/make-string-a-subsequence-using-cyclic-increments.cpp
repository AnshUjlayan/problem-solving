class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str2.size() > str1.size()) {
            return false;
        }
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < str1.size() && ptr2 < str2.size()) {
            char c = 'a' + ((str1[ptr1] - 'a') + 1) % 26;
            if(str1[ptr1] == str2[ptr2] || c == str2[ptr2]) {
                ptr1++;
                ptr2++;
            }
            else {
                ptr1++;
            }
        }
        return ptr2 == str2.size();
    }
};