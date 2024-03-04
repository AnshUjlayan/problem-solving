class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size() - 1, score = 0;
        while (l <= r) {
            if (tokens[l] <= power) {
                power -= tokens[l++];
                score++;
            }
            else if (score && r - l >= 2) {
                power += tokens[r--];
                score--;
            }
            else {
                break;
            }
        }
        return score;
    }
};