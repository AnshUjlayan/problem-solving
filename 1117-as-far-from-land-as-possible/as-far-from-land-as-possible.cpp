class Solution {
  public:
    struct cell {
      int x, y, dist;
      cell(int x, int y, int dist) : x(x), y(y), dist(dist) {}
    };

    int maxDistance(vector<vector<int>>& grid) {
      vector<pair<int,int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      int n = grid.size(), result = -1;
      auto outOfBounds = [&] (int x, int y) ->bool {
        return x < 0 || y < 0 || x >= n || y >= n;
      };
      queue<cell> q;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          if(grid[i][j] == 1) {
            q.push(cell(i, j, 0));
          }
        }
      }
      while(!q.empty()) {
        cell currCell = q.front();
        q.pop();
        for(auto& [dirX, dirY] : dirs) {
          int x = currCell.x + dirX;
          int y = currCell.y + dirY;
          if(!outOfBounds(x, y) && grid[x][y] == 0) {
            result = currCell.dist + 1;
            grid[x][y] = 1;
            q.push(cell(x, y, currCell.dist + 1));
          }
        }
      }
      return result;
    }
};