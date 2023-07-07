class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char,int> ump;
        int l = 0, r = 0;
        while(r < answerKey.size()) {
            ump[answerKey[r++]]++;
            if(min(ump['T'], ump['F']) > k)
                ump[answerKey[l++]]--;
        }
        return r - l;
    }
};