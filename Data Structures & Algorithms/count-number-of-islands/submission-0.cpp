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

        for (int i=0 ; i<grid.size() ; ++i) {
            for (int j=0 ; j<grid[0].size() ; ++j) {
                if (visited[i][j] || grid[i][j] != '1')
                    continue;
                
                islands++;
                currentIsland.push({i,j});
                while (!currentIsland.empty()) {
                    auto land = currentIsland.front();
                    currentIsland.pop();

                    if (land.first < 0
                        || land.first >= ROWS
                        || land.second < 0
                        || land.second >= COLS
                        || visited[land.first][land.second]
                        || grid[land.first][land.second] != '1')
                        continue;

                    visited[land.first][land.second] = true;
                    currentIsland.push({land.first + 1, land.second});
                    currentIsland.push({land.first, land.second + 1});
                    currentIsland.push({land.first - 1, land.second});
                    currentIsland.push({land.first, land.second - 1});
                }
            }
        }

        return islands;
    }
};
