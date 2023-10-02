class Solution {
public:
    bool winnerOfGame(string colors) {
        int A = 0, B = 0;
        int l = 0, r = 0;
        while(r <= colors.size()) {
            if(r == colors.size() || colors[r] != colors[l]) {
                int len = max(0, r - l - 2);
                A += colors[l] == 'A' ? len : 0;
                B += colors[l] == 'B' ? len : 0;
                l = r;
            }
            r++;
        }
        return A > B;
    }
};