class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        unordered_map<char,int> dirX, dirY;
        st.insert({0, 0});
        dirX['E'] = 1;
        dirX['W'] = -1;
        dirY['N'] = 1;
        dirY['S'] = -1;
        int x = 0, y = 0;
        for(char& c : path) {
            x += dirX[c];
            y += dirY[c];
            if(st.count({x, y})) {
                return true;
            }
            st.insert({x, y});
        }
        return false;
    }
};