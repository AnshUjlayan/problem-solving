class Solution {
public:
    struct Node {
        int i, j, time;
        Node(int i, int j, int time) : i(i), j(j), time(time) {}
    };
    struct CompareNode {
        bool operator()(const Node& a, const Node& b) {
            return a.time > b.time;
        }
    };
    bool isValid(int x, int y, int n) {
        return x < n && y < n && x >= 0 && y >= 0;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<Node, vector<Node>, CompareNode> pq;
        vector<vector<int>> visited(n, vector<int>(n, false));
        vector<pair<int,int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        pq.push(Node(n - 1, n - 1, grid[n - 1][n - 1]));
        visited[n - 1][n - 1] = true;
        while(!pq.empty()) {
            auto [i, j, time] = pq.top();
            pq.pop();
            if(i == 0 && j == 0) {
                return time;
            }
            for(auto& [dirX, dirY] : dirs) {
                int x = i + dirX;
                int y = j + dirY;
                if(isValid(x, y, n) && !visited[x][y]) {
                    pq.push(Node(x, y, max(time, grid[x][y])));
                    visited[x][y] = true;
                }
            }
        }
        return -1;
    }
};