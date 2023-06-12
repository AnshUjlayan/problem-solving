class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int turn = 0, n = word1.size(), m = word2.size(), ptr1 = 0, ptr2 = 0;
        string str = "";
        while(ptr1 < n || ptr2 < m) {
            if(!turn) {
                if(ptr1 < n)
                    str += word1[ptr1++];
                else
                    str += word2[ptr2++];
            }
            else {
                if(ptr2 < m) 
                    str += word2[ptr2++];
                else
                    str += word1[ptr1++];
            }
            turn = 1 - turn;
        }
        return str;
    }
};