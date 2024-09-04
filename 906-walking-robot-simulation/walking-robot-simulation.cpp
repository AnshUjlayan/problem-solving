class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        set<pair<int, int>> st;
        for (const auto& obs : obstacles) {
            st.emplace(obs[0], obs[1]);
        }

        vector<int> xDirs {0, 1, 0, -1};
        vector<int> yDirs {1, 0, -1, 0};
        
        int x = 0, y = 0;
        int dir = 0;
        int maxDist = 0;

        for (int command : commands) {
            if (command == -1) {
                dir = (dir + 1) % 4;
            } else if (command == -2) {
                dir = (dir + 3) % 4;
            } else {
                while (command--) {
                    int nextX = x + xDirs[dir];
                    int nextY = y + yDirs[dir];
                    if (st.find({nextX, nextY}) != st.end()) {
                        break;
                    } else {
                        x = nextX;
                        y = nextY;
                        maxDist = max(maxDist, x * x + y * y);
                    }
                }
            }
        }
        return maxDist;
    }
};