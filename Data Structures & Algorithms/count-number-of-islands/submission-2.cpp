class Solution {
public:
    int ROWS, COLS;
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++; 
                }
            }
        }
        return count;
    }
private:
        void dfs(vector<vector<char>>& grid, int r, int c){
            grid[r][c] = '0'; 
            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};
            for(int i = 0; i < 4; i++){
                int next_r = r+ dr[i];
                int next_c = c+dc[i]; 
                bool safe = next_r >= 0 && next_r < ROWS && next_c >= 0 && next_c < COLS;  
                if(safe && grid[next_r][next_c] == '1') {
                    dfs(grid, next_r, next_c);
                }
            }
        }   
};
