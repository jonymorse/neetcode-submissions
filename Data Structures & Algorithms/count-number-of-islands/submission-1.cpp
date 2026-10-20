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
            if(grid[r][c]  == '0') return; 
            grid[r][c] = '0'; 
            if(r-1 >= 0) dfs(grid, r-1, c);
            if(r+1 < ROWS) dfs(grid, r+1, c);
            if(c-1 >= 0) dfs(grid, r, c-1);
            if(c+1 < COLS) dfs(grid, r, c+1); 
            return;
        }   
};
