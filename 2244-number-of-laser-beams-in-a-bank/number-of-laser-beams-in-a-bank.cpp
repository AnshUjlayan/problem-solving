class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevCams = 0, result = 0;
        for(string& row : bank) {
            int cams = 0;
            for(char& c : row) {
                if(c == '1') {
                    cams++;
                }
            }
            if(!cams) {
                continue;
            }
            result += prevCams * cams;
            prevCams = cams;
        }
        return result;
    }
};