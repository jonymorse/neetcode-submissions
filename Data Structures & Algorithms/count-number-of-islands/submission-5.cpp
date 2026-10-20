#include <array>

class Solution {
public:
    void DFS(vector<vector<char>>& grid, int r, int c)
    {
        grid[r][c] = '0';
        array<pair<int, int>, 4> ns = {{
            { r + 1, c},
            { r, c + 1},
            { r - 1, c},
            { r, c - 1},
        }};

        for (auto& [nr, nc] : ns) {
            if (
                0 <= nr && nr < grid.size() &&
                0 <= nc && nc < grid[0].size() &&
                grid[nr][nc] == '1'
            )
                DFS(grid, nr, nc);
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int count = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    DFS(grid, r, c);
                    count++;
                }
            }
        }
        return count;
    }
};