class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int,int>> currentIsland;

        int islands = 0;
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        for (int i=0 ; i<ROWS ; ++i) {
            for (int j=0 ; j<COLS ; ++j) {
                if (visited[i][j] || grid[i][j] != '1')
                    continue;
                
                islands++;
                currentIsland.push({i,j});
                while (!currentIsland.empty()) {
                    auto [x, y] = currentIsland.front();
                    currentIsland.pop();

                    if (x < 0
                        || x >= ROWS
                        || y < 0
                        || y >= COLS
                        || visited[x][y]
                        || grid[x][y] != '1')
                        continue;

                    visited[x][y] = true;
                    currentIsland.push({x + 1, y});
                    currentIsland.push({x, y + 1});
                    currentIsland.push({x - 1, y});
                    currentIsland.push({x, y - 1});
                }
            }
        }

        return islands;
    }
};
